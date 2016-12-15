//
// Created by galit on 12/12/16.
//

#include "CreateDriver.h"

/**
 * class CreateDriver
 * a class that create a driver
 */

CreateDriver::CreateDriver(string &input) : Create(input) {

}

Driver *CreateDriver::getDriver()  {
    int id;
    int age;
    string stat;
    int exp;

    if (this->tokens.size()!=5){
        return NULL;
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
    //create a driver according to the parameters
    return  new Driver(id ,age,stat,exp);

}

//get the vehicle id
int CreateDriver::getVehicle_id() const {
    return vehicle_id;
}
