#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <string.h>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include "Controller.h"
#include "CreateGrid.h"
#include "CreateDriver.h"
#include "CreateCar.h"
#include "CreateRide.h"


using namespace std;

/**
 * destructor
 */
Controller::~Controller() {
    delete center;
    for (vector<int>::iterator iterator1 = client_socket.begin(); iterator1 != client_socket.end(); iterator1++) {
        close(*(iterator1));
    }
}

/**
 * constructor that create connetion with socket
 * @param port
 * @return
 */
Controller::Controller(const short unsigned int &port) : UDP(port) {
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
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(this->port);
    if (bind(socketnum, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding to socket");
    }
/*
    client_socket = vector<int>();
    getCommend();///to build one time at least
    pthread_t id;
    struct parameters *p = new struct parameters();
    p->m = this;
    pthread_create(&id, NULL, this->staticForChose, (void *) p);
*/
}

/**
 * send msg in sock with given id
 * @param str what we want to send
 * @param id socket id -more relavent to tcp
 */
void Controller::sendMessage(std::string &str, int id) {
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    string ip_address="127.0.0.1";
    sin.sin_addr.s_addr = inet_addr(ip_address.c_str());
    sin.sin_port = htons(this->port);
    const char * datas = str.c_str();
    int data_len = str.length() + 1;
    //send
    int sent_bytes = sendto(this->socketnum,datas, data_len, 0, (struct sockaddr *) &sin, sizeof(sin));
//	cout << sent_bytes << endl;
    //check if send successfully
    if (sent_bytes < 0) {
            return perror("client error ");
    }
}

/**'
 *
 * wait to get messege from socket
 * @param id socket id
 * @return the string of want we got
 */
std::string Controller::getMessage(int id) {
    struct sockaddr_in to;
    char buffer[4050];
    unsigned int to_len = sizeof(struct sockaddr_in);
    //receive
    int bytes = recvfrom(this->socketnum,
                         buffer, sizeof(buffer) , 0, (struct sockaddr *) &to, &to_len);
    //set the port number to the new one which we get with the data
    this->port = ntohs(to.sin_port);
    //check if receive successfully

//    cout << bytes << endl;
    if (bytes < 0) {
        perror("fail to rec data");
    }
    string str(buffer, sizeof(buffer));
    return str;
}

/**
 * with tcp we will get new client and give him socket id uniqe to him
 */
void Controller::getNewClient() {
    if (listen(this->socketnum, 5) < 0) {//we can get max of 5 client
        perror("error listening to a socket");
    }
    unsigned int addr_len = sizeof(client_socket);
    client_socket.push_back(accept(this->socketnum, (struct sockaddr *) &this->client_socket, &addr_len));

    if (client_socket.front() < 0) {
        perror("error accepting client");
    }

}


/**
 * constructor
 * @return
 */
Controller::Controller() : UDP() {
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
void *Controller::getCommend() {
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

    }
}

/**
 * run the loop and get number of drivers and give each driver the nessercy data
 * @return true if works
 */
bool Controller::runDriver() {
    int i;
    cin >> i;
    while (i) {
        string serial_str=getMessage(this->socketnum);
        Driver *gp2;
        boost::iostreams::basic_array_source<char> device(serial_str.c_str(), serial_str.size());
        boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
        boost::archive::binary_iarchive ia(s2);
        ia >> gp2;
        center->addDriver(gp2);
        i--;
        center->setTaxiToDriver(0, 0);
        Car *car = center->getCars()[gp2->getId()];
        string car_string;
        boost::iostreams::back_insert_device<std::string> inserter2(car_string);
        boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s3(inserter2);
        boost::archive::binary_oarchive a2(s3);
        a2 << car;
        s3.flush();
        sendMessage(car_string, socketnum);//serlize the car and send to driver
        string s =getMessage(socketnum);
        if ( s.compare("Wait for trip")) {
            std :: cout << "Wrong massege\n";
            return false;
        }
        getNewTrip();

    }
    return true;
}
void Controller::getNewTrip(){
    string trip_string;
    if (!center->getTrip().empty()) {
        SearchableTrip *trip = center->getTrip()[0];
        center->getTrip().erase(center->getTrip().begin());//erase the trip
        center->getDrivers()[center->getFree_drivers().front()]->setTrip(trip);
        boost::iostreams::back_insert_device<std::string> inserter_trip(trip_string);
        boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s_trip(inserter_trip);
        boost::archive::binary_oarchive a_trip(s_trip);
        a_trip << trip;
        s_trip.flush();
        sendMessage(trip_string, socketnum);//serlize the trip and send to driver
    }
    string st = getMessage(socketnum);
    if (st.compare("Wait for advance")){
        std :: cout << "Wrong massege\n";
        return ;
    }
}
/***
 * for use in seprate thred we need static method
 * @param parameters
 * @return
 */
void *Controller::staticForChose(void *parameters) {
    struct parameters *par = (struct parameters *) parameters;
    par->m->getCommend();
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
        CreateRide *cd = new CreateRide(parm);
        time = cd->time;
        SearchableTrip *trip;
        trip = new SearchableTrip(center->getLayout(), cd->start_x,
                                  cd->star_y, cd->end_x, cd->end_y, cd->id, cd->tariff, cd->numOfPass);
        center->getTrip().insert(std::pair<int, SearchableTrip *>(center->getTrip().size(), trip));
        trip->setTime(cd->time);
        if(!center->getFree_drivers().empty()){
            getNewTrip();
        }
        delete cd;
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
        center->addCar(cc->getId(), cc->getManufactor(), cc->getColor(), cc->getKind());
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
    center->printLocation(id);
    return true;
}

/**
 * run all current driver that have a trip to finish point
 * @return
 */
bool Controller::CommendSix() {
    center->finishAllTrip();
    return true;
}

bool Controller::CommendNine() {
    if(this->time < center->getDrivers()[0]->getTrip()->getTime()){
        this->time++;
    }
    else if(this->time >= center->getDrivers()[0]->getTrip()->getTime()){
        string str;
        center->getDrivers()[0]->move();
        boost::iostreams::back_insert_device<std::string> inserter2(str);
        boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > se(inserter2);
        boost::archive::binary_oarchive arr(se);
        arr << center->getDrivers()[0]->curr_pos;
        se.flush();
        this->time++;
        sendMessage(str,socketnum);
        string string1 =getMessage(socketnum);

        if (string1.compare("Finished trip")) {
            if (!center->getTrip().empty()){
                center->setTrip(center->getTrip());
            }
            else{
                center->getFree_drivers().push_back(center->getDrivers()[0]->getId());
            }
        }
    }
    return true;
}

