#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include "Controller.h"
#include "Creation/CreateGrid.h"
#include "Creation/CreateDriver.h"
#include "Creation/CreateCar.h"
#include "Creation/CreateRide.h"
#include <cstring>
#include <boost/iostreams/device/array.hpp>
#include <boost/archive/binary_iarchive.hpp>


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

Controller::Controller(const short unsigned int &port) : UDP(port) {
    center = new TaxiCenter();
    string sizeGride;
    getline(cin, sizeGride);
    char tmp[10];
    int h;
    int w;
    //  cin>>h;
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
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(this->port);
    if (bind(this->socketnum, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    client_socket = vector<int>();
    getCommend();///to build one time at least
    pthread_t id;
    struct parameters *p = new struct parameters();
    p->m = this;
    pthread_create(&id, NULL, this->staticForChose, (void *) p);

}
/**
 * send msg in sock with given id
 * @param str what we want to send
 * @param id socket id -more relavent to tcp
 */
void Controller::sendMessage(std::string &str, int id) {
    int sent_bytes = send(socketnum, str.c_str(), str.length(), 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }

}
/**'
 *
 * wait to get messege from socket
 * @param id socket id
 * @return the string of want we got
 */
std::string Controller::getMessage(int id) {
    char buffer[4096] = {0};
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(socketnum, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        perror("connection is closed");
    } else if (read_bytes < 0) {
        perror("error");
    }
    return buffer;
}
/**
 * with tcp we will get new client and give him socket id uniqe to him
 */
void Controller::getNewClient() {
    if (listen(this->socketnum, 5) < 0) {//we can get max of 5 client
        perror("error listening to a socket");
    }
    unsigned int addr_len = sizeof(client_socket);
    client_socket.push_back(accept(this->socketnum,  (struct sockaddr *) &this->client_socket,  &addr_len));

    if (client_socket.front() < 0) {
        perror("error accepting client");
    }

}

void Controller::setClientSocketNum(int sockNum) {
    this->client_socket.push_back(sockNum);
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
    //  cin>>h;
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
                success=runDriver();
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
                center->getDrivers()[0]->move();
                this->time++;
                break;

        }
        cin >> commend;

    }
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
        Driver *gp = new Driver(0,0,"m",0)  ;
        std::string serial_str;
        boost::iostreams::back_insert_device<std::string> inserter(serial_str);
        boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
        boost::archive::binary_oarchive oa(s);
        oa <<gp;
        s.flush();
        cout << serial_str << endl;
      //  getNewClient();
        // serial_str=getMessage(this->socketnum);
        Driver *gp2;
        boost::iostreams::basic_array_source<char> device(serial_str.c_str(), serial_str.size());
        boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
        boost::archive::binary_iarchive ia(s2);
        ia >> gp2;
i--;
         center->setTaxiToDriver(0,0);
        Car* car=center->getCars()[gp2->getId()];
        //std::string serial_str;
        boost::iostreams::back_insert_device<std::string> inserter2(serial_str);
        boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s3(inserter2);
        boost::archive::binary_oarchive a2(s3);
        a2 <<car;
        s.flush();
        sendMessage(serial_str,socketnum);//se
        // nd the serilze car to driver
        if (!center->getTrip().empty()){
            SearchableTrip* trip=center->getTrip()[0];
            center->getTrip().erase(center->getTrip().begin());//erase the trip
            center->getDriver(gp2->getId())->setTrip(trip);
            boost::iostreams::back_insert_device<std::string> inserter_trip(serial_str);
            boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s_trip(inserter_trip);
            boost::archive::binary_oarchive a_trip(s_trip);
            a_trip <<trip;
            s.flush();
            sendMessage(serial_str,socketnum);//se
        }

    }
    return true;
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
 * commend one meaning create a driver
 * will call the class that phase the input and create driver
 * @return true is creation succes false if we got exception
 */
bool Controller::CommendOne() {
    string parm;
    cin >> parm;
    try {
        CreateDriver *cd = new CreateDriver(parm);
        center->addDriver(cd->getId(), cd->getAge(), cd->getStat(), cd->getExp());
        center->setTaxiToDriver(cd->getId(), cd->getVehicle_id());
        delete cd;
    } catch (std::exception exception1) {
        return false;
    }

    return true;
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
        time=cd->time;
        SearchableTrip* trip;
        trip=new SearchableTrip(center->getLayout(),cd->start_x,
                                cd->star_y, cd->end_x,cd->end_y,cd->id, cd->tariff,cd->numOfPass);
        center->getTrip().insert(std::pair<int,SearchableTrip*>(center->getTrip().size(),trip));
        trip->setTime(cd->time);
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

