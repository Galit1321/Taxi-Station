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
    /**
     * class tp phase the creation of a new car
     */
    int id;
    int kind;
    string color;
    string manufactor;

public:
    CreateCar(string &input);//constructor
    //return the id of the car
    int getId() const;
    //return the kind of the car
    int getKind() const;
    //return the color of the car
    const string &getColor() const;
    //return the manufactor of the car
    const string &getManufactor() const;
};


#endif //ADVPRO01_CREATECAR_H
