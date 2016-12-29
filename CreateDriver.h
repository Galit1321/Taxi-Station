
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
    CreateDriver(string &input);
    int getId() const;

    int getAge() const;

    const string &getStat() const;

    int getExp() const;

    int getVehicle_id() const;

    virtual ~CreateDriver();
};


#endif //ADVPRO01_CREATEDRIVER_H
