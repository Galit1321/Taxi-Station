
//
// Created by galit on 12/12/16.
//

#ifndef ADVPRO01_CREATEDRIVER_H
#define ADVPRO01_CREATEDRIVER_H

#include "Create.h"

class CreateDriver: public  Create{
    /**
     * class to pahse the creation of driver
     */
private:
    int id;
    int age;
    string stat;
    int exp;
    int vehicle_id;
public:
    CreateDriver(string &input);//conatructor
    int getId() const;//return the id of the driver

    int getAge() const;//return the age of the driver

    const string &getStat() const;//return the status of the driver

    int getExp() const;//return the expirience of the driver

    int getVehicle_id() const;//return the vechile id of the driver

    virtual ~CreateDriver();//deconstructor
};


#endif //ADVPRO01_CREATEDRIVER_H
