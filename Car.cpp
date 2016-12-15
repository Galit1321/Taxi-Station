//
// Created by michal on 12/1/16.
//

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

Car ::Car(int id,string carType ,string manufacturer,string color){
    id = id;
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
    return ((id == getId())&&(carType == getCarType())&&
            (manufacturer == getManufacturer())&& (color == getColor()));
}

double Car::getTariff() const {
    return tariff;
}

void Car::setTariff(double tariff) {
    Car::tariff = tariff;
}

string Car::getCarType() const {
    return carType;
}

void Car::setCarType(CarType carType) {
    Car::carType = carType;
}

