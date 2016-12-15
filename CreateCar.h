//
// Created by galit on 12/12/16.
//

#ifndef ADVPRO01_CREATECAR_H
#define ADVPRO01_CREATECAR_H

using namespace std;

#include "string"
#include "Car.h"
#include "Create.h"
#include "TaxiCab.h"
#include "Luxury.h"

/**
 * class CreateCar
 * a class that create a car
 */
class CreateCar: public Create {

public:
    //create a car
    CreateCar(string &input);
    //set the car parameters by the input and create the car
    Car* getCar();
};


#endif //ADVPRO01_CREATECAR_H
