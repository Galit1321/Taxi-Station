//
// Created by michal on 12/1/16.
//

#include "Driver.h"

/**
 * default constructor
 * @return
 */
Driver ::Driver() {}

/**
 * copy constructor
 * @param obj
 * @return copy of the given object
 */
Driver ::Driver(Driver &object) {
    this->id = object.getId();


}
//constructor
Driver ::Driver(int id ,int age ,string stat , int experience) {
    id = id;
    age = age;
    stat = stat;
    experience =experience;
}

//find the distance from the driver curr pose
//to the given point
int Driver ::getDistance(Point point) {
    return 0;
}

//compare between 2 drivers
bool Driver ::operator==(const Driver &driver1) const {
    return ((id == driver1.getId())&&(stat == driver1.getStat())
    &&(age == driver1.getAge())&&(experience == driver1.getExperience()));
    return  0;
}

//run the bfs algoritm
Solution* Driver ::doBFS(Point psEnd) {
    return NULL;
}

//return the driver id
int Driver::getId() const {
    return id;
}

//return the driver age
int Driver::getAge() const {
    return age;
}

//return the years of experience of the driver
int Driver::getExperience() const {
    return experience;
}

//return the num of the users
int Driver::getNumOfUser() const {
    return numOfUser;
}

//set the driver id
void Driver::setId(int id) {
    Driver::id = id;
}

//set the driver age
void Driver::setAge(int age) {
    Driver::age = age;
}

//set the years of experience of the driver
void Driver::setExperience(int experience) {
    Driver::experience = experience;
}

//set the num of the users
void Driver::setNumOfUser(int numOfUser) {
    Driver::numOfUser = numOfUser;
}

//set the status of the driver
void Driver::setStat(string stat) {
    Driver::stat = stat;
}

//set the car of the driver
void Driver::setCar(Car *car) {
    Driver::car = car;
}

//return the status of the driver
string Driver::getStat() const {
    return stat;
}

////return the car of the driver
Car *Driver::getCar() const {
    return car;
}


SearchableTrip *Driver::getTrip() const {
    return trip;
}


void Driver::setTrip(SearchableTrip *trip) {
    Driver::trip = trip;
}





