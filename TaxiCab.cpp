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
    mileage = 0;
    id=0;
}

/**
 * constructor
 * @param manufacturer1 - the manufacturer of the car
 * @param color1 - the color of the car
 * @return
 */
TaxiCab::TaxiCab(int id ,string manufacturer1 ,string color1){
    this->id = id;
    mileage = 0;
    manufacturer =  manufacturer1;
    color = color1;
    tariff = 0;
}
/**
 * constructor
 * @param id -  the id of the car
 * @param mileage - the mile that passed
 * @param manufacturer1 - the manufacturer of the car
 * @param color1 - the color of the car
 * @param tariff1 - the tariff of the ride
 * @return
 */
TaxiCab ::TaxiCab(int id, int mileage,string manufacturer1, string color1, int tariff1) {
    id = id;
    mileage = mileage;
    manufacturer = manufacturer1;
    color = color1;
    tariff = tariff1;
}

//get the tariff of the trip
int TaxiCab ::getCost() {
    return tariff;
}


