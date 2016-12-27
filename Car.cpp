//
// Created by michal on 12/1/16.
//

#include <boost/serialization/nvp.hpp>
#include "Car.h"
#include "string"
/**
 * default constructor
 * @return
 */

using namespace std;

Car::Car() {
id=0;
}
/**
 * constructor
 * @param id
 * @param carType
 * @param manufacturer
 * @param color
 * @return
 */
Car ::Car(int id,string carType ,string manufacturer,string color){
    this->id = id;
    carType = carType;
    manufacturer = manufacturer;
    color= color;
    mileage =0;
}


//return the id of the car
int Car::getId() const {
    return id;
}

// return the mileage that have passed
int Car::getMileage() const {
    return mileage;
}

// set the color of the car
string Car::getColor() const {
    return color;
}

// get the manufacture of the car
string Car::getManufacturer() const {
    return manufacturer;
}

//set the id of the car
void Car::setId(int id) {
    Car::id = id;
}

// set the mileage of the car
void Car::setMileage(int mileage) {
    Car::mileage = mileage;
}

// set the color of the car
void Car::setColor(string color) {
    Car::color = color;
}

// set the manufacture of the car
void Car::setManufacturer(string manufacturer) {
    Car::manufacturer = manufacturer;
}
//compare between to cars
bool Car::operator==(const Car &car) const {
    return ((id == getId())&&(kind == getKind())&&
            (manufacturer == getManufacturer())&& (color == getColor()));
}

//get the tariff of the trip
double Car::getTariff() const {
    return tariff;
}

//set the tariff of the trip
void Car::setTariff(double tariff) {
    Car::tariff = tariff;
}



int Car::getKind() const {
    return kind;
}
