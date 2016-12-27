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
#include "CreateGrid.h"
#include "CreateDriver.h"
#include "CreateCar.h"
#include "CreateRide.h"
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
  /*  client_socket = vector<int>();
    getCommend();///to build one time at least
    pthread_t id;
    struct parameters *p = new struct parameters();
    p->m = this;
    pthread_create(&id, NULL, this->staticForChose, (void *) p);*/

}

void Controller::sendMessage(std::string &str, int id) {
    int sent_bytes = send(socketnum, str.c_str(), str.length(), 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }

}

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

void Controller::getNewClient() {
    this->time = 0;
    unsigned int addr_len = sizeof(int);
int i=accept(this->socketnum, (struct sockaddr *) &this->client_socket, &addr_len);
    client_socket.push_back(i);

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
                runDriver();
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
  //  pthread_exit(0);
}

bool Controller::runDriver() {
    int i;
    cin >> i;
    while (i) {
        Driver *gp = new Driver(0,0,"m",0)  ;

        std::string serial_str;
        boost::iostreams::back_insert_device<std::string> inserter(serial_str);
        boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
        boost::archive::binary_oarchive oa(s);
        oa << gp;
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
    }
    return true;
}

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
        center->getTrip().insert(std::pair<int,SearchableTrip*>(center->getTrip().size(),new SearchableTrip(center->getLayout(), cd->start_x, cd->star_y, cd->end_x, cd->end_y, cd->id, cd->tariff,cd->numOfPass)));
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

