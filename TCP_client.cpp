//
// Created by galit on 12/01/17.
//
#include <cstring>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include "Create.h"
#include "CreateDriver.h"
#include "Driver.h"
#include "TCP_client.h"

using namespace std;
TCP_client::TCP_client(const unsigned short &port,const char* ip) {
  this->socket1=new Tcp(false,port);
    this->socket1->initialize();
}
TCP_client::~TCP_client() {
delete  socket1;
}



/*
 * the function run the client flow
 */

void TCP_client::runDriver(){
    string parm;
    cin>>parm;
    CreateDriver* cd=new CreateDriver(parm);
    Driver* d= new Driver(cd->getId(),cd->getAge(),cd->getStat(),cd->getExp());
    setDriver(d);
    std::string serial_str;
    delete cd;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << driver;
    s.flush();
    this->socket1->sendData(serial_str,this->socket1->socketDescriptor);
    char bufCar[4096];
    int serial_car = this->socket1->reciveData(bufCar,4096,this->socket1->socketDescriptor);
    Car *car;
    boost::iostreams::basic_array_source<char> device(bufCar, serial_car);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> car;
    driver->setCar(car);
    char bufTrip[4096];
    int serial_trip = this->socket1->reciveData(bufTrip,4096,this->socket1->socketDescriptor);
    SearchableTrip *trip ;
    boost::iostreams::basic_array_source<char> device1(bufTrip, serial_trip);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s3(device1);
    boost::archive::binary_iarchive ar(s3);
    ar >> trip;
    this->driver->setTrip(trip);
    move();


}

void TCP_client::move() {
    char bufP[4096];
    char buf[4096];
   int ser_point = this->socket1->reciveData(bufP,4096,this->socket1->socketDescriptor);
    Point* p;
    while ((this->driver->curr_pos!=this->driver->getTrip()->getGoalState())&&(string(bufP)!="STOP")){
        if(string(bufP)=="Go"){
            this->driver->move();
            this->timeClient++;
            ser_point = this->socket1->reciveData(buf,4096,this->socket1->socketDescriptor);
        }else if ((string(bufP)=="STOP")&&(string(bufP)=="STOP")){
            break;
        }
     }
    if ((string(bufP)=="STOP")&&(string(bufP)=="STOP")) {
        setNewTrip();
    }
}

/**
 * set new trip to our driver
 */
void TCP_client::setNewTrip(){
    char buf[4096];
    int serial_trip = this->socket1->reciveData(buf,4096,this->socket1->socketDescriptor);
    if (string(buf)=="STOP"){
        return;
    }
    SearchableTrip *trip ;
    boost::iostreams::basic_array_source<char> device1(buf, serial_trip);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s3(device1);
    boost::archive::binary_iarchive ar(s3);
    ar >> trip;
    driver->setTrip(trip);
      move();
}

Driver *TCP_client::getDriver() const {
    return driver;
}

void TCP_client::setDriver(Driver *driver) {
    TCP_client::driver = driver;
}
