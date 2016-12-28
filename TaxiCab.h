//
// Created by michal on 12/1/16.
//

#ifndef EX2_TAXICAB_H
#define EX2_TAXICAB_H

#include <boost/serialization/base_object.hpp>
#include "Car.h"
using namespace std;

#include "string"

class TaxiCab : public Car{
public:

    TaxiCab();//defult conatructor
    //Taxi cab constructor
    TaxiCab(int id ,int mileage ,string manufacturer1 ,string color1 ,int tariff1);
    //Taxi cab constructor
    TaxiCab(int id ,string manufacturer1 ,string color1);
    //get the tariff of the trip
    int getCost();
    //make one move
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        /*
selize*/
        ar & boost::serialization::base_object<Car>(*this);

    }
    };


#endif //EX2_TAXICAB_H
