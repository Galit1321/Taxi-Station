//
// Created by michal on 12/1/16.
//

#ifndef EX2_TAXICAB_H
#define EX2_TAXICAB_H

#include "Car.h"


class TaxiCab : public Car{
public:
    // the cost of the drive
    int tariff;
    TaxiCab();//defult conatructor
    //Taxi cab constructor
    TaxiCab(long id ,int mileage ,Manufacturer manufacturer1 ,Color color1 ,int tariff1);
    //get the tariff of the trip
    int getCost();
    //make one move
    virtual void move();

};


#endif //EX2_TAXICAB_H
