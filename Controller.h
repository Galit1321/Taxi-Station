//
// Created by galit on 12/12/16.
//

#ifndef ADVPRO01_CONTROLLER_H
#define ADVPRO01_CONTROLLER_H

#include "Point.h"
#include "TaxiCenter.h"
using namespace std;

class Controller {
public:
    TaxiCenter* center;
    virtual ~Controller();
    Controller();
    void getCommend();
protected:
    bool CommendOne();
    bool CommendTwo();
    bool CommendThree();
    bool CommendFour();
    bool CommendSix();
};


#endif //ADVPRO01_CONTROLLER_H
