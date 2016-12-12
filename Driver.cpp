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
   // this->id = object.

}
//constructor
Driver ::Driver(int id, int age, int experience, string stat) {
    id = id;
    age = age;
    experience =experience;
    stat =stat;
}

//find the distance from the driver curr pose
//to the given point
int Driver ::getDistance(Point point) {
    return 0;
}

//compare between 2 drivers
bool Driver ::operator==(const Driver &driver1) const {
    return 0;
}

//run the bfs algoritm
Solution* Driver ::doBFS(Point psEnd) {
    return NULL;
}

//return the driver id
int Driver::getId() const {
    return 0;
}

//return the driver age
int Driver::getAge() const {
    return 0;
}

//return the years of experience of the driver
int Driver::getExperience() const {
    return 0;
}

//return the num of the users
int Driver::getNumOfUser() const {
    return 0;
}

//set the driver id
void Driver::setId(long id) {
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
void Driver::setStat(status stat) {
    Driver::stat = stat;
}

//set the car of the driver
void Driver::setCar(TaxiCab *car) {
    Driver::car = car;
}

//return the status of the driver
status Driver::getStat() const {
    return status ::DIVORCED;
}

//return the car of the driver
TaxiCab* Driver::getCar() const {
    return NULL;
}
