//
// Created by galit on 12/12/16.
//

#ifndef ADVPRO01_CREATEDRIVER_H
#define ADVPRO01_CREATEDRIVER_H

#include "Create.h"
#include "Driver.h"

/**
 * class CreateDriver
 * a class that create a driver
 */

class CreateDriver: public  Create{
private:
    int id;
    int age;
    string stat;
    int exp;
    int vehicle_id;
public:
    CreateDriver(string &input);
    int getId() const;

    int getAge() const;

    const string &getStat() const;

    int getExp() const;

    int getVehicle_id() const;

    virtual ~CreateDriver();
};


#endif //ADVPRO01_CREATEDRIVER_H
