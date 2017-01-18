#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <thread>
#include "Controller.h"
#include "CreateGrid.h"
#include "CreateCar.h"
#include "CreateRide.h"
#include "Tcp.h"
int driverL = true;

/**
 * destructor
 */
Controller::~Controller() {
    delete center;
//    Controller::finish= true;
    delete  connection;
}

/**
 * constructor that create connetion with socket
 * @param port
 * @return
 */
Controller::Controller(const short unsigned int &port)  {
    this->connection=new Tcp(true,port);
    connection->initialize();
//    Controller::finish=false;
  //  connection->socketDescriptor;
    center = new TaxiCenter();
    string sizeGride;
    getline(cin, sizeGride);
    char tmp[10];
    int h;
    int w;
    int pos = sizeGride.find(" ");
    h = atoi(strcpy(tmp, sizeGride.substr(0, pos).c_str()));
    sizeGride.erase(0, pos + 1);
    w = atoi(sizeGride.c_str());
    int numOfObs;
    cin >> numOfObs;
    string obsVector;
    vector<int> v;
    if (numOfObs) {
        while (numOfObs) {
            cin >> obsVector;
            CreateGrid *size;
            size = new CreateGrid(obsVector);
            v.insert(v.end(), size->getInput().begin(), size->getInput().end());
            delete size;
            numOfObs--;
        }
        center->setLayout(h, w, &v);

    } else {
        center->setLayout(h, w);
    }

/*
    client_socket = vector<int>();
*/

}




/**
 * constructor
 * @return
 */
Controller::Controller() {
    center = new TaxiCenter();
    string sizeGride;
    getline(cin, sizeGride);
    char tmp[10];
    int h;
    int w;
    int pos = sizeGride.find(" ");
    h = atoi(strcpy(tmp, sizeGride.substr(0, pos).c_str()));
    sizeGride.erase(0, pos + 1);
    w = atoi(sizeGride.c_str());
    int numOfObs;
    cin >> numOfObs;
    string obsVector;
    vector<int> v;
    if (numOfObs) {
        while (numOfObs) {
            cin >> obsVector;
            CreateGrid *size;
            size = new CreateGrid(obsVector);
            v.insert(v.end(), size->getInput().begin(), size->getInput().end());
            delete size;
            numOfObs--;
        }
        center->setLayout(h, w, &v);

    } else {
        center->setLayout(h, w);
    }
}

/**
 * busy waiting function to get commend from user
 * destion to run on diff thred
 */
void Controller::getCommend() {
    int commend;
    cin >> commend;
   bool success = true;
    while ((commend != 7) && (success)) {
        switch (commend) {
            case 1:
                success = runDriver();
                break;
            case 2:
                success = CommendTwo();
                break;
            case 3:
                success = CommendThree();
                break;
            case 4:
                success = CommendFour();
                break;
            case 6:
                success = CommendSix();
                break;
            case 9:
                success=CommendNine();
                break;

        }
        cin >> commend;
    }string s="STOP";
    if (commend == 7){
        driverL= false;
        closeAllClients();
    }
   // connection->sendData(s);///////////////////////////////////////
    pthread_exit(0);
}

/**
 * run the loop and get number of drivers and give each driver the nessercy data
 * @return true if works
 */
bool Controller::runDriver() {
    int i;
    cin >> i;
    while (i) {
        int sockNum = this->connection->getNewClient();
        pthread_t id;
        struct parameters* p = new struct parameters();
        p->c= this;
       p->client_sock = sockNum;
        int status = pthread_create(&id, NULL,this->runClient ,(void*)p);
        if(status) {
            break;
        }
        i--;
    }
    return true;
}
void* Controller::runClient(void* parameters) {
    struct parameters* par = (struct parameters*)parameters;
    char buf[4096];
    int serial_str =par->c->connection->reciveData(buf,4096,par->client_sock);
    Driver *gp2;
    boost::iostreams::basic_array_source<char> device(buf, serial_str);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> gp2;
    par->c->getCenter()->addDriver(gp2);
    par->c->client_map.insert(pair<int,int>(par->client_sock,gp2->getId()));
    Car *car = par->c->getCenter()->getCars()[0];
    par->c->getCenter()->setTaxiToDriver(gp2->getId(), car->getId());
    std::string car_string;
    boost::iostreams::back_insert_device<std::string> inserter(car_string);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
   oa << car;
    s.flush();
    par->c->connection->sendData(car_string,par->client_sock);//serlize the car and send to driver
    par->c->getNewTrip( par->client_sock);

    return NULL;
    }


bool Controller::getNewTrip(int client_id){
    Driver* driver=getCenter()->getDriver(client_map[client_id]);
    getCenter()->getFree_drivers().push_back(driver->getId());
    string trip_string;
    while (true){
        SearchableTrip* trip=driver->getTrip();
        if (trip!=NULL) {
            boost::iostreams::back_insert_device<std::string> inserter_trip(trip_string);
            boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s_trip(inserter_trip);
            boost::archive::binary_oarchive a_trip(s_trip);
            a_trip << trip;
            s_trip.flush();
            connection->sendData(trip_string,client_id);//serlize the trip and send to driver*/
            this->busy.push_back(client_id);
            break;
        }else{
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
    while(driverL){
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

}

void* Controller::createPthread(void* parameters){
    struct parameters *p = (struct parameters*)parameters;
    CreateRide* cd=new CreateRide(p->str);
    SearchableTrip *trip;
    trip = new SearchableTrip(p->c->getCenter()->getLayout(), cd->start_x,
                              cd->star_y, cd->end_x, cd->end_y, cd->id, cd->tariff, cd->numOfPass);
    trip->setTime(cd->time);
    p->c->getCenter()->getTrip().insert(std::pair<int, SearchableTrip *>(p->c->getCenter()->getTrip().size(), trip));
    delete cd;
}

/**
 * commend two that create a new ride
 * @return true if action sucessful otherwise false
 */
bool Controller::CommendTwo() {
    string parm;
    cin >> parm;
    try {
      pthread_t id ;
        struct parameters *p = new struct parameters();
        p->c=this;
        p->str=parm;
        int status = pthread_create(&id, NULL,this->createPthread,(void*)p);
      if(status){
           cout<<"error in open thread to trip";
        }

    } catch (std::exception exception1) {
        return false;
    }
    return true;
}

/**
 * commend 3 to create a new car with agrument
 * given by cin
 * @return true if we success
 */
bool Controller::CommendThree() {
    string parm;
    cin >> parm;
    try {
        CreateCar *cc = new CreateCar(parm);
        getCenter()->addCar(cc->getId(), cc->getManufactor(), cc->getColor(), cc->getKind());
        delete cc;
    }
    catch (std::exception e) {
        return false;
    }
    return true;

}

/**
 * commend 4 is to get the current position of driver with
 * id given in cin>>id and print it to screen
 * @return true if we found the driver and printed ,ohterwise false
 */
bool Controller::CommendFour() {
    int id;
    cin >> id;
   getCenter()->printLocation(id);
    return true;
}

/**
 * run all current driver that have a trip to finish point
 * @return
 */
bool Controller::CommendSix() {
    getCenter()->finishAllTrip();
    return true;
}


/**
 * commend 9 wait for the right time and make move
 * when the right time comes
 * @return true
 */
bool Controller::CommendNine() {
    SearchableTrip* trip=getCenter()->getTrip()[0];
    if (trip!=NULL) {
        if (this->servertime < trip->getTime()) {
            this->servertime++;
        } else if (this->servertime == trip->getTime()) {
            Driver *d = getCenter()->findCloser(trip->getInitialState());
            if (d != NULL) {
                d->setTrip(trip);
                getCenter()->getTrip().erase(getCenter()->getTrip().begin());
            }}}
        std::string str="Go";
        for (std::vector<int>::iterator it = busy.begin(); it != busy.end(); it++){
            Driver* driver= getCenter()->getDrivers()[this->client_map[*it]];
            driver->move();
            //getCenter()->move(this->client_map[*it]);
            this->servertime++;
            connection->sendData(str,*it);
            if (driver->getCurr_pos()==driver->getTrip()->getGoalState()) {
                driver->setTrip(NULL);
                getCenter()->getFree_drivers().push_back(driver->getId());
                getNewTrip(*it);
            }
        }
    return true;
    }


TaxiCenter *Controller::getCenter()  {
    pthread_mutex_t lock;
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        // error
    }
    pthread_mutex_lock(&lock);
    return center;
    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);
}

 void Controller::closeAllClients() {
     for(it = client_map.begin(); it != client_map.end(); it++){
         string s="STOP";
         connection->sendData(s, it->first);
     }
 }