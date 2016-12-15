//
// Created by michal on 12/1/16.
//

#ifndef EX2_LUXURY_H
#define EX2_LUXURY_H

#include "TaxiCab.h"

class Luxury :public  TaxiCab{
public:

    //defult
    Luxury(int id, string manufacturer2, string color2) ;
    Luxury();
    //Taxi cab constructor
    Luxury(int id, int mileage, string manufacturer2, string color2, double tariff2) ;
};


#endif //EX2_LUXURY_H
