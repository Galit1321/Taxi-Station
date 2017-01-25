//
// Created by michal on 12/1/16.
//
#include <boost/serialization/nvp.hpp>
#include "Driver.h"

/**
 * default constructor
 * @return
 */
Driver ::Driver() :Person(){
    id=0;
    age =0;
    experience =0;
    stat = " ";
    car = NULL;
   trip=NULL;
    satisfaction=0.0;
    startTrip=false;

}

/**
 * copy constructor
 * @param obj
 * @return copy of the given object
 */
Driver ::Driver(Driver &object) {
    this->id = object.getId();
    this->experience = object.getExperience();
    this->age = object.getAge();
    this->stat = object.getStat();
    this->curr_pos = object.getCurr_pos();
    trip=object.getTrip();
    startTrip=false;
}
//constructor
Driver ::Driver(int id ,int age ,string stat , int experience) {
    this->id = id;
    this->age = age;
    this->stat = stat;
    this->experience =experience;
    car = NULL;
    trip=NULL;
    startTrip=false;
}

Driver::~Driver() {



    startTrip=false;
}


//compare between 2 drivers
bool Driver ::operator==(const Driver &driver1) const {
    return ((id == driver1.getId())&&(stat == driver1.getStat())
    &&(age == driver1.getAge())&&(experience == driver1.getExperience()));

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
/**
 * finish the driver trip
 */
void Driver::finishTrip() {
    int cont=this->trip->solution.size();
    for (int i=0;i<cont;i++){
        move();
    }

}

/**
 *
 * @param layout1
 * @param start_i
 * @param start_j
 * @param end_i
 * @param end_j
 * @param rid
 * @param tff
 * @param nop
 */

void Driver::setTrip(SearchableTrip* trip1) {

    this->trip=trip1;
    if(trip1!=NULL){
        this->numOfUser+=trip->getNumOfPass();
    }


}
/**
 * driver move a qeure accoding to kind of car
 */
void Driver::move() {
    if (!trip->solution.empty()){
        if (car->getKind()==1){
            setCurr_pos(trip->solution.front());
            this->car->setMileage(this->car->getMileage()+1);
            trip->solution.pop_front();
        }
       else{
            setCurr_pos(trip->solution.front());
            trip->solution.pop_front();
            this->car->setMileage(this->car->getMileage()+1);
            if (!trip->solution.empty()){
                setCurr_pos(trip->solution.front());
                trip->solution.pop_front();
                this->car->setMileage(this->car->getMileage()+1);
            }

        }
    }
}
/**
 * add the satisfaction to total of that we have
 * @param satisfaction
 */
void Driver::setSatisfaction(float satisfaction) {
    this->satisfaction=(this->satisfaction*(numOfUser-trip->getNumOfPass())+satisfaction)/(float)this->numOfUser;
}\
/**
 * get setsatfaction
 * @return
 */
float Driver::getSatisfaction() {
    return  this->satisfaction;
}






