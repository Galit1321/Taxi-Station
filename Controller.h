//
// Created by galit on 12/12/16.
//

#ifndef ADVPRO01_CONTROLLER_H
#define ADVPRO01_CONTROLLER_H

#include "Point.h"
#include "TaxiCenter.h"
using namespace std;

class Controller {
    /**
     * class to controller the input in front
     * of the main function
     */
public:
    TaxiCenter* center;
    virtual ~Controller();//desrectir
    Controller();//consterctor
    void getCommend();//busy wating method to get num of commend
protected:
    bool CommendOne();
    bool CommendTwo();
    bool CommendThree();
    bool CommendFour();
    bool CommendSix();
};


#endif //ADVPRO01_CONTROLLER_H
