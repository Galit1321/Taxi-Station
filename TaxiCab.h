//
// Created by michal on 12/1/16.
//

#ifndef EX2_TAXICAB_H
#define EX2_TAXICAB_H

#include "Car.h"
using namespace std;

#include "string"

class TaxiCab : public Car{
public:

    TaxiCab();//defult conatructor
    //Taxi cab constructor
    TaxiCab(int id ,int mileage ,string manufacturer1 ,string color1 ,int tariff1);
    TaxiCab(int id ,string manufacturer1 ,string color1);
    //get the tariff of the trip
    int getCost();
    //make one move


};


#endif //EX2_TAXICAB_H
