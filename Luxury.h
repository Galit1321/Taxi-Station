//
// Created by michal on 12/1/16.
//

#ifndef EX2_LUXURY_H
#define EX2_LUXURY_H

#include <boost/serialization/base_object.hpp>
#include "Car.h"

class Luxury :public  Car{
    /*
     *
     *class of luxury car that will move twice as fast and will cost twice as much
     */
public:

    //constructor
    Luxury(int id, string manufacturer2, string color2) ;
    //defult constructor
    Luxury();
    //Taxi cab constructor
    Luxury(int id, int mileage, string manufacturer2, string color2, double tariff2) ;
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        /*
selize*/
        ar & boost::serialization::base_object<Car>(*this);

    }
    };


#endif //EX2_LUXURY_H
