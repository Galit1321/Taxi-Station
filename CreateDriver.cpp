//
// Created by galit on 12/12/16.
//

#include "CreateDriver.h"

/*
 * constructor
 */
CreateDriver::CreateDriver(string &input) : Create(input) {
    if (this->tokens.size()!=5){
        return;
    }
    list<string>::iterator iterator1=this->tokens.begin();
    id=std::stoi(*iterator1);
    iterator1++;
    age=std::stoi(*iterator1);
    iterator1++;
    stat=*(iterator1);
    iterator1++;
    exp=std::stoi(*iterator1);
    iterator1++;
    vehicle_id=std::stoi(*iterator1);
}

/**
 * getter of vehicle_id
 * @return
 */

int CreateDriver::getVehicle_id() const {
    return vehicle_id;
}
/**
 * destructpor
 */
CreateDriver::~CreateDriver() {

}
/**
 * getter of id
 * @return
 */
int CreateDriver::getId() const {
    return id;
}
/**
 * getter of age
 * @return
 */
int CreateDriver::getAge() const {
    return age;
}
/**
 * getter of statuse
 * @return
 */
const string &CreateDriver::getStat() const {
    return stat;
}
/**
 * getter of driver experion
 * @return
 */
int CreateDriver::getExp() const {
    return exp;
}
