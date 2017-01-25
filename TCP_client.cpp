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
    this->ip=ip;
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
    if (!cd->isWork()){
        string s="close";
        this->socket1->sendData(s,this->socket1->socketDescriptor);
        return;
    }
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
    char bufCar[65536];
    int serial_car = this->socket1->reciveData(bufCar,4096,this->socket1->socketDescriptor);
    Car *car;
    boost::iostreams::basic_array_source<char> device(bufCar, serial_car);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> car;
    driver->setCar(car);
    char bufTrip[65536];
    int serial_trip = this->socket1->reciveData(bufTrip,65536,this->socket1->socketDescriptor);
    SearchableTrip *trip ;
    boost::iostreams::basic_array_source<char> device1(bufTrip, serial_trip);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s3(device1);
    boost::archive::binary_iarchive ar(s3);
    ar >> trip;
    this->driver->setTrip(trip);
    this->socket1->sendData("ok",this->socket1->socketDescriptor);
    move();


}

void TCP_client::move() {
    char bufP[4096];
    string ok="ok";
    int ser_point = this->socket1->reciveData(bufP,4096,this->socket1->socketDescriptor);
    this->socket1->sendData(ok,this->socket1->socketDescriptor);
    std::size_t foundS = string(bufP).find("STOP");
    while ((string(bufP)!="STOP")&& (string(bufP)!="STOP")&&(foundS==std::string::npos)){
        std::size_t found = string(bufP).find("Go");
        foundS = string(bufP).find("STOP");
        if(found!=std::string::npos){
            this->driver->move();
            this->timeClient++;
            this->socket1->sendData("ok",this->socket1->socketDescriptor);
            if (this->driver->curr_pos==this->driver->getTrip()->getGoalState()){
                setNewTrip();
                break;
            }
            ser_point = this->socket1->reciveData(bufP,4096,this->socket1->socketDescriptor);

        }else if ((string(bufP)=="STOP")|| (string(bufP)=="STOP")){
            break;
        }
    }

}

/**
 * set new trip to our driver
 */
void TCP_client::setNewTrip(){
    char buf[65536];
    int serial_trip = this->socket1->reciveData(buf,4096,this->socket1->socketDescriptor);
    std::size_t foundS = string(buf).find("STOP");
    if (foundS!=std::string::npos){
        return;
    }
    SearchableTrip *trip ;
    boost::iostreams::basic_array_source<char> device1(buf, serial_trip);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s3(device1);
    boost::archive::binary_iarchive ar(s3);
    ar >> trip;
    driver->setTrip(trip);
    this->socket1->sendData("ok",this->socket1->socketDescriptor);
    move();
}

void TCP_client::setDriver(Driver *driver) {
    TCP_client::driver = driver;
}