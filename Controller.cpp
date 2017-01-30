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
    pool.terminate();
    delete center;
    delete connection;
}

/**
 * constructor that create connetion with socket
 * @param port
 * @return
 */
Controller::Controller(const short unsigned int &port):pool(5) {
    this->connection = new Tcp(true, port);
    connection->initialize();
    center = new TaxiCenter();
    bool check= init();
    while(!check){
        cout<<"-1"<<endl;
        check=init();

    }

}


/**
 * constructor
 * @return
 */
Controller::Controller():pool(5){
    center = new TaxiCenter();
    init();
}
bool Controller::init() {
    string sizeGride;
    getline(cin, sizeGride);
    char tmp[10];
    int h;
    int w;
    int pos = sizeGride.find(" ");
    if (pos==std::string::npos){
        return false;
    }
    if(  sizeGride.find_first_not_of("0123456789 ")!=std::string::npos){
        return false;
    }
    h = atoi(strcpy(tmp, sizeGride.substr(0, pos).c_str()));
    sizeGride.erase(0, pos + 1);
    w = atoi(sizeGride.c_str());
    if ((h<1)||(w<1)){
        return false;
    }
    string numOfObs;
    getline(cin, numOfObs);
    if (numOfObs.find_first_not_of("0123456789")!=std::string::npos){

        return false;
    }
    string obsVector;
    vector<int> v;
    int obs=stoi(numOfObs);
    if (obs) {
        while (obs) {
            getline(cin ,obsVector);
            CreateGrid *size;
            size = new CreateGrid(obsVector);
            if(!size->isWork()){
                delete size;
                return false;
            }
            v.insert(v.end(), size->getInput().begin(), size->getInput().end());
            delete size;
           obs--;
        }
        center->setLayout(h, w, &v);

    } else {
        center->setLayout(h, w);
    }
    return true;
}
/**
 * busy waiting function to get commend from user
 * destion to run on diff thred
 */
void Controller::getCommend() {
    int commend;
    string s;
    getline(cin,s);
    commend=stoi(s);
    bool success;
    while ((commend != 7)) {
        success=true;
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
                success = CommendNine();
                break;

            default:
                cout<<"-1"<<endl;
                break;
        }
        if (!success){
            cout<<"-1"<<endl;
        }
        string s;
        getline(cin,s);
        if (s.find_first_not_of("1234679")!=std::string::npos){
            getline(cin,s);
        }
        commend=stoi(s);
    }
    driverL = false;
    closeAllClients();


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
        pthread_t  id2;
        struct parameters *p = new struct parameters();
        p->c = this;
        p->client_sock = sockNum;
        char buf[4096];
        int serial_str = connection->reciveData(buf, 4096, sockNum);
        int find=string(buf).find("close");
        if (find!=std::string::npos){
            return false;
        }
        Driver *gp2;
        pthread_t id;
        boost::iostreams::basic_array_source<char> device(buf, serial_str);
        boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
        boost::archive::binary_iarchive ia(s2);
        ia >> gp2;
        cout.flush();
        getCenter()->addDriver(gp2);
        client_map.insert(pair<int, int>(sockNum, gp2->getId()));
        ID_map.insert(pair<int, int>( gp2->getId(),sockNum));
        Car *car = getCenter()->getCars()[gp2->getId()];
        std::string car_string;
        boost::iostreams::back_insert_device<std::string> inserter(car_string);
        boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
        boost::archive::binary_oarchive oa(s);
        oa << car;
        s.flush();
        p->client_id=gp2->getId();
        connection->sendData(car_string, sockNum);//serlize the car and send to driver
        gp2->setCar(car);
        int status = pthread_create(&id, NULL, getNewTrip, (void *) p);
        if (status) {
            cout<<"error in creating new trip thread"<<endl;
        }
        pthread_join(id, NULL);
        pthread_create(&id2, NULL, runClient, (void *) p);
        i--;
    }
    return true;
}

void *Controller::runClient(void *parameters) {
    struct parameters *par = (struct parameters *) parameters;
    while (!par->c->getCenter()->getDriver(par->client_id)->startTrip) {
        sleep(1);
    }
    while (driverL){
        sleep(1);
    }
    return NULL;
}


void *Controller::getNewTrip(void *parameters) {
    struct parameters *p = (struct parameters *) parameters;
    Driver *driver = p->c->getCenter()->getDriver(p->client_id);
    p->c->getCenter()->getFree_drivers().push_back(driver->getId());
    while (driverL) {
        if (!p->c->getCenter()->getTrip().empty()) {
            std::map<int,SearchableTrip*> map = p->c->getCenter()->getTrip();
            std::map<int, SearchableTrip *>::iterator iterator1;
            for (iterator1 = map.begin(); iterator1 != map.end(); iterator1++) {
                SearchableTrip *trip = iterator1->second;
                if (!trip->isBelong()) {
                    trip->setBelong(true);
                    driver->setTrip(trip);
                    break;
                } else {
                    continue;
                }
            } break;
        } else {
            sleep(1);
        }
    }
    return NULL;

}


void* Controller::createPthread(void *parameters) {
    struct parameters *p = (struct parameters *) parameters;
    CreateRide *cd = new CreateRide(p->str,p->c->getCenter()->getLayout()->getHeight()
            ,p->c->getCenter()->getLayout()->getWidth());
    if(!cd->isWork()){
        delete cd;
        cout<<"-1"<<endl;
        return NULL;

    }
    SearchableTrip *trip = p->c->getCenter()->addTrip(p->c->getCenter()->getLayout(), cd->start_x,
                                                      cd->star_y, cd->end_x, cd->end_y, cd->id, cd->tariff,
                                                      cd->numOfPass);
    if(trip->solution.empty()){
        cout<<"-1"<<endl;
        delete cd;
        delete trip;
        return NULL;
    }
   if( p->c->getCenter()->getLayout()->getMatrix()[cd->start_x][cd->star_y]==1){
       cout<<"-1"<<endl;
       delete cd;
       delete trip;
       return NULL ;
   }
    if( p->c->getCenter()->getLayout()->getMatrix()[cd->end_x][cd->end_y]==1){
        cout<<"-1"<<endl;
        delete cd;
        delete trip;
        return NULL ;
    }
    trip->setTime(cd->time);
    p->c->getCenter()->getTrip().insert(std::pair<int, SearchableTrip *>(cd->time, trip));
    delete cd;
    return NULL;
}

/**
 * commend two that create a new ride
 * @return true if action sucessful otherwise false
 */
bool Controller::CommendTwo() {
    string parm;
    getline(cin,parm);
    try {
        struct parameters *p = new struct parameters();
        p->c = this;
        p->str = parm;
        Job* task=new Job(createPthread,p);
        pool.addJob(task);

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
    getline(cin,parm);
    if(parm.find_first_not_of("0123456789STFH,RBGPW")!=std::string::npos){
        return false;
    }
    try {
        CreateCar *cc = new CreateCar(parm);
        if (!cc->isWork()){
            delete cc;
            return false;
        }
        Car* c=  getCenter()->addCar(cc->getId(), cc->getManufactor(), cc->getColor(), cc->getKind());
        getCenter()->getCars()[cc->getId()]=c;
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
    cin>>id;

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
    sleep(1);
    this->servertime++;
    std::string str = "Go";
    for (std::vector<int>::iterator itB = busy.begin(); itB != busy.end(); itB++) {
        Driver *d = getCenter()->getDrivers()[this->client_map[*itB]];
        d->move();
        connection->sendData(str, *itB);
        char buffer[4045];
        connection->reciveData(buffer,4045,*itB);
        if (d->getCurr_pos() == d->getTrip()->getGoalState()) {
            busy.erase(itB);
            d->setTrip(NULL);
            getCenter()->getFree_drivers().push_back(d->getId());
            d->startTrip = false;
            itB--;
            pthread_t id;
            struct parameters *p = new struct parameters();
            p->client_sock = *itB;
            p->c = this;
            int status = pthread_create(&id, NULL, this->getNewTrip, (void *) p);
            if (status) {
                break;
            }
        }
    }
    SearchableTrip *trip;
    std::map<int, SearchableTrip *> map1 = getCenter()->getTrip();
    if(map1.empty()){
        return true;
    }
    std::map<int, SearchableTrip *>::iterator iterator1;
    for (iterator1 = map1.begin(); iterator1 != map1.end(); iterator1++) {
        if (iterator1->second->isBelong()) {
            trip = iterator1->second;
            break;
        } else {
            trip = NULL;
        }
    }
    if (trip != NULL) {
        if (this->servertime < trip->getTime()) {

        } else if (this->servertime == trip->getTime()) {
            Driver *d = getCenter()->findCloser(trip->getInitialState());
            getCenter()->getTrip().erase(trip->getTime());
            if (d != NULL) {
                d->startTrip = true;
                getCenter()->getFree_drivers().erase(find(getCenter()->getFree_drivers().begin(),getCenter()->getFree_drivers().end(),d->getId()));
                busy.push_back(ID_map[d->getId()]);
                string trip_string;
                boost::iostreams::back_insert_device<std::string> inserter_trip(trip_string);
                boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s_trip(inserter_trip);
                boost::archive::binary_oarchive a_trip(s_trip);
                a_trip << trip;
                s_trip.flush();
                this->connection->sendData(trip_string,ID_map[d->getId()]);//serlize the trip and send to driver*/
                char buf[40];
                this->connection->reciveData(buf,40,ID_map[d->getId()]);
            }
        }
    }

    return true;
}


TaxiCenter *Controller::getCenter() {
    boost::unique_lock<boost::mutex> scoped_lock(mutex);
    return center;

}

void Controller::closeAllClients() {
    std::map<int, int>::iterator it;
    for (it = client_map.begin(); it != client_map.end(); it++) {
        string s = "STOP";
        connection->sendData(s, it->first);
    }
}