//
// Created by michal on 12/1/16.
//

#include "Luxury.h"

//constructor
Luxury ::Luxury(int id, int mileage, string manufacturer2, string color2, double tariff2) {
    id = id;
    mileage = mileage;
    manufacturer = manufacturer2;
    color = color2;
    tariff = 2*tariff2;
}
//constructor
Luxury ::Luxury() {}
/**
 * construcrote
 * @param id
 * @param manufacturer2
 * @param color2
 * @return
 */
Luxury::Luxury(int id, string manufacturer2, string color2) {
    this->id = id;
    this->mileage = 0;
    manufacturer = manufacturer2;
    color = color2;
    kind=2;
}