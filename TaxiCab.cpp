//
// Created by michal on 12/1/16.
//

#include "TaxiCab.h"

/**
 * defult constructor
 * @return
 */
TaxiCab ::TaxiCab() {
    tariff=0;
}

/**
 * constructor
 * @return
 */
TaxiCab ::TaxiCab(long id, int mileage, Manufacturer manufacturer1, Color color1, int tariff1) {
    id = id;
    mileage = mileage;
    manufacturer = manufacturer1;
    color = color1;
    tariff = tariff1;
}

//get the tariff of the trip
int TaxiCab ::getCost() {
    return 0;
}

//make one move
void TaxiCab ::move() {

}