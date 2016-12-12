//
// Created by galit on 12/12/16.
//

#ifndef ADVPRO01_CREATEDRIVER_H
#define ADVPRO01_CREATEDRIVER_H

#include "Create.h"
#include "Driver.h"
class CreateDriver: public  Create{
private:
    Driver* driver;
    int vehicle_id;
public:
    CreateDriver(string &input);

    Driver *getDriver() const;

    int getVehicle_id() const;
};


#endif //ADVPRO01_CREATEDRIVER_H
