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
    delete connection;
}

/**
 * constructor that create connetion with socket
 * @param port
 * @return
 */
Controller::Controller(const short unsigned int &port) {
    this->connection = new Tcp(true, port);
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
                success = CommendNine();
                break;

        }
        cin >> commend;
    }
    driverL = false;
    closeAllClients();

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
        pthread_t  id2;
        struct parameters *p = new struct parameters();
        p->c = this;
        p->client_sock = sockNum;
 //       runClient((void *) p);
      pthread_create(&id2, NULL, runClient, (void *) p);
        i--;
    }
    return true;
}

void *Controller::runClient(void *parameters) {
    struct parameters *par = (struct parameters *) parameters;
    char buf[4096];
    int serial_str = par->c->connection->reciveData(buf, 4096, par->client_sock);
    Driver *gp2;
    pthread_t id;
    boost::iostreams::basic_array_source<char> device(buf, serial_str);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> gp2;
    cout.flush();
    par->c->getCenter()->addDriver(gp2);
    par->c->client_map.insert(pair<int, int>(par->client_sock, gp2->getId()));
    Car *car = par->c->getCenter()->getCars()[gp2->getId()];
    std::string car_string;
    boost::iostreams::back_insert_device<std::string> inserter(car_string);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << car;
    s.flush();

    par->c->connection->sendData(car_string, par->client_sock);//serlize the car and send to driver
    gp2->setCar(car);
    int status = pthread_create(&id, NULL, par->c->getNewTrip, (void *) par);
    if (status) {
       cout<<"error in creating new trip thread"<<endl;
    }
    pthread_join(id, NULL);
    while (!gp2->startTrip) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    par->c->busy.push_back(par->client_sock);
    while (driverL){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return NULL;
}


void *Controller::getNewTrip(void *parameters) {
    struct parameters *p = (struct parameters *) parameters;
    Driver *driver = p->c->getCenter()->getDriver(p->c->client_map[p->client_sock]);
    p->c->getCenter()->getFree_drivers().push_back(driver->getId());
    string trip_string;
    while (true) {
        if (!p->c->getCenter()->getTrip().empty()) {
            std::map<int, SearchableTrip *> map1 = p->c->getCenter()->getTrip();
            std::map<int, SearchableTrip *>::iterator iterator1;
            for (iterator1 = map1.begin(); iterator1 != map1.end(); iterator1++) {
                SearchableTrip *trip = iterator1->second;
                if (!trip->isBelong()) {
                    trip->setBelong(true);
                    driver->setTrip(trip);
                    boost::iostreams::back_insert_device<std::string> inserter_trip(trip_string);
                    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s_trip(inserter_trip);
                    boost::archive::binary_oarchive a_trip(s_trip);
                    a_trip << trip;
                    s_trip.flush();
                    p->c->connection->sendData(trip_string, p->client_sock);//serlize the trip and send to driver*/
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

void *Controller::createPthread(void *parameters) {
    struct parameters *p = (struct parameters *) parameters;
    CreateRide *cd = new CreateRide(p->str);
    SearchableTrip *trip = p->c->getCenter()->addTrip(p->c->getCenter()->getLayout(), cd->start_x,
                                                      cd->star_y, cd->end_x, cd->end_y, cd->id, cd->tariff,
                                                      cd->numOfPass);
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
    cin >> parm;
    try {
        pthread_t id;
        struct parameters *p = new struct parameters();
        p->c = this;
        p->str = parm;
       // this->createPthread((void *) p);
       int status = pthread_create(&id, NULL, this->createPthread,(void *) p );
        if (status) {
            cout << "error in open thread to trip";
        }
        pthread_join(id, NULL);
        sleep(1);
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
    this->servertime++;
    std::string str = "Go";
    for (std::vector<int>::iterator it = busy.begin(); it != busy.end(); it++) {
        Driver *driver = getCenter()->getDrivers()[this->client_map[*it]];
        driver->move();
        connection->sendData(str, *it);

        if (driver->getCurr_pos() == driver->getTrip()->getGoalState()) {
            busy.erase(it);
            driver->setTrip(NULL);
            getCenter()->getFree_drivers().push_back(driver->getId());
            driver->startTrip = false;
            it--;
            pthread_t id;
            struct parameters *p = new struct parameters();
            p->client_sock = *it;
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