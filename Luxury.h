//
// Created by michal on 12/1/16.
//

#ifndef EX2_LUXURY_H
#define EX2_LUXURY_H

#include "TaxiCab.h"

class Luxury :public  TaxiCab{
public:
    //make one move
    void move();
    //defult constructor
    Luxury();
    //Taxi cab constructor
    Luxury(int id, int mileage, Manufacturer manufacturer2, Color color2, double tariff2) ;
};


#endif //EX2_LUXURY_H
