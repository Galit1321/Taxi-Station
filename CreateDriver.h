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
    Driver* driver;
    int vehicle_id;
public:
    CreateDriver(string &input);
    //create a driver
    Driver *getDriver() ;
    //get the vehicle id
    int getVehicle_id() const;
};


#endif //ADVPRO01_CREATEDRIVER_H
