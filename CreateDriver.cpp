//
// Created by galit on 12/12/16.
//

#include "CreateDriver.h"

/**
 * class CreateDriver
 * a class that create a driver
 */

CreateDriver::CreateDriver(string &input) : Create(input) {
    if (this->tokens.size()!=5){
        return;
    }
    //set all the car parameter according to the input
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

//get the vehicle id
int CreateDriver::getVehicle_id() const {
    return vehicle_id;
}

CreateDriver::~CreateDriver() {

}

int CreateDriver::getId() const {
    return id;
}

int CreateDriver::getAge() const {
    return age;
}

const string &CreateDriver::getStat() const {
    return stat;
}

int CreateDriver::getExp() const {
    return exp;
}
