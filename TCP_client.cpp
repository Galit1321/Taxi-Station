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
TCP_client::TCP_client(const unsigned short &port,const char* ip) : TCP(port) {
    this->ip = ip;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(this->ip);
    sin.sin_port = htons(this->port);
    if (connect(this->socketnum, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
}
}

TCP_client::~TCP_client() {

}

/*
 * the function send message for the server.
 * it get the string message to send and send it.
 */
void TCP_client::sendMessage (std::string &str,int sock) {
    int sent_bytes = send(this->socketnum, str.c_str(), str.length(), 0);
    if (sent_bytes < 0) {
        perror("error");
    }
}

/*
 * the function get message from the server.
 * it get the message,change it to string and return it
 */
std::string TCP_client::getMessage (int sock) {
    char buffer[4096] = {0};
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(this->socketnum, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        perror("connection is closed");
    }
    else if (read_bytes < 0) {
        perror("error");
    }
    return buffer;
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
    sendMessage(serial_str, 0);
    string serial_car = getMessage(0);
    Car *car;
    boost::iostreams::basic_array_source<char> device(serial_car.c_str(), serial_car.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> car;
    driver->setCar(car);
    string serial_trip = getMessage(0);
    SearchableTrip *trip ;
    boost::iostreams::basic_array_source<char> device1(serial_trip.c_str(), serial_trip.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s3(device1);
    boost::archive::binary_iarchive ar(s3);
    ar >> trip;
    this->driver->setTrip(trip);
    move();


}

void TCP_client::move() {
    string ser_point ;
    ser_point = getMessage(0);
    Point* p;
    while ((this->driver->curr_pos!=this->driver->getTrip()->getGoalState())&&(ser_point.find("STOP")==std::string::npos)){
        boost::iostreams::basic_array_source<char> device2(ser_point.c_str(), ser_point.size());
        boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s4(device2);
        boost::archive::binary_iarchive ar1(s4);
        ar1>>p;
        this->driver->setCurr_pos(p);
        this->time++;
        ser_point = getMessage(0);
    }
    if (ser_point.find("STOP")==std::string::npos) {
        setNewTrip();
    }
}

/**
 * set new trip to our driver
 */
void TCP_client::setNewTrip(){
    string serial_trip = getMessage(0);
    if (serial_trip.find("STOP")!=std::string::npos){
        return;
    }
    SearchableTrip *trip ;
    boost::iostreams::basic_array_source<char> device1(serial_trip.c_str(), serial_trip.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s3(device1);
    boost::archive::binary_iarchive ar(s3);
    ar >> trip;
    driver->setTrip(trip);
    //  move();
}

Driver *TCP_client::getDriver() const {
    return driver;
}

void TCP_client::setDriver(Driver *driver) {
    TCP_client::driver = driver;
}
