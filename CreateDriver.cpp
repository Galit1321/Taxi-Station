//
// Created by galit on 12/12/16.
//

#include "CreateDriver.h"

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
    list<string>::iterator iterator1=this->tokens.begin();
    id=atoi(*iterator1);
    iterator1++;
    age=atoi(*iterator1);
    iterator1++;
    stat=*(iterator1);
    iterator1++;
    exp=atoi(*iterator1);
    iterator1++;
    vehicle_id=atoi(*iterator1);
    return  new Driver(id,age,exp,stat);

}

int CreateDriver::getVehicle_id() const {
    return vehicle_id;
}
