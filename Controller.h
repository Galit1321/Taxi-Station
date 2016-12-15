//
// Created by galit on 12/12/16.
//

#ifndef ADVPRO01_CONTROLLER_H
#define ADVPRO01_CONTROLLER_H

#include "Point.h"
#include "TaxiCenter.h"
using namespace std;
/**
 * class controller
 * a class that works ith the main and get the commands
 * from the user
 */
class Controller {
public:
    TaxiCenter* center;
    virtual ~Controller();
    Controller();
    //get a commend from the user
    void getCommend();
protected:
    //create a driver and return true if the creation succes
    bool CommendOne();
    //create a ride and return true if the creation succes
    bool CommendTwo();
    //create a car and return true if the creation succes
    bool CommendThree();
    //print the current position of the driver
    bool CommendFour();
    //finish the trip
    bool CommendSix();
};


#endif //ADVPRO01_CONTROLLER_H
