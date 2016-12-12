//
// Created by galit on 12/12/16.
//

#ifndef ADVPRO01_CONTROLLER_H
#define ADVPRO01_CONTROLLER_H

#include "TaxiCenter.h"
using namespace std;

class Controller {
protected:
    TaxiCenter* center;
    virtual ~Controller();
    Controller();
    void getCommend();
    bool CommendOne();
    bool CommendTwo();
    bool CommendThre();
    string CommendFour();
    bool CommendSix();
    void exit();

};


#endif //ADVPRO01_CONTROLLER_H
