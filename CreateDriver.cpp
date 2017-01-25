//
// Created by galit on 12/12/16.
//

#include "CreateDriver.h"

/*
 * constructor
 */
CreateDriver::CreateDriver(string &input) : Create(input) {
    if (this->tokens.size()!=5){
        work = false;
    }
    list<string>::iterator iterator1=this->tokens.begin();
    if (((*iterator1).find_first_not_of("0123456789") == std::string::npos)||((*iterator1) == "0")){
        work = false;
    }
    id=std::stoi(*iterator1);
    iterator1++;
    if (((*iterator1).find_first_not_of("0123456789") == std::string::npos)||((*iterator1) == "0")){
        work = false;
    }
    age=std::stoi(*iterator1);
    iterator1++;
    stat=*(iterator1);
    iterator1++;
    if (((*iterator1).find_first_not_of("0123456789") == std::string::npos)||((*iterator1) == "0")){
        work = false;
    }
    exp=std::stoi(*iterator1);
    if (((*iterator1).find_first_not_of("0123456789") == std::string::npos)||((*iterator1) == "0")){
        work = false;
    }
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
