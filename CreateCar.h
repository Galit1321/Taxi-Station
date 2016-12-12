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
class CreateCar: public Create {

public:
    CreateCar(string &input);

    Car* getCar();
};


#endif //ADVPRO01_CREATECAR_H
