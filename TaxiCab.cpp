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
TaxiCab::TaxiCab(int id ,string manufacturer1 ,string color1){
    this->id = id;
    mileage = 0;
    //manufacturer  manufacturer1; NEED TO BE IF CLUSE
    //color = color1; NEED IF CLUSE
    tariff = 0;
}
/**
 * constructor
 * @return
 */
TaxiCab ::TaxiCab(int id, int mileage,string manufacturer1, string color1, int tariff1) {
    id = id;
    mileage = mileage;
    //manufacturer = manufacturer1;
    //color = color1;
    tariff = tariff1;
}

//get the tariff of the trip
int TaxiCab ::getCost() {
    return tariff;
}

//make one move
void TaxiCab ::move() {

}
