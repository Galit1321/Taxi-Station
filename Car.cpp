//
// Created by michal on 12/1/16.
//

#include "Car.h"

/**
 * default constructor
 * @return
 */
Car::Car() {

}


//return the id of the car
long Car::getId() const {
    return 0;
}

// return the mileage that have passed
int Car::getMileage() const {
    return 0;
}

// set the color of the car
Color Car::getColor() const {
    return Color ::RED;
}

// get the manufacture of the car
Manufacturer Car::getManufacturer() const {
    return Manufacturer::HONDA;
}

//set the id of the car
void Car::setId(long id) {
    Car::id = id;
}

// set the mileage of the car
void Car::setMileage(int mileage) {
    Car::mileage = mileage;
}

// set the color of the car
void Car::setColor(Color color) {
    Car::color = color;
}

// set the manufacture of the car
void Car::setManufacturer(Manufacturer manufacturer) {
    Car::manufacturer = manufacturer;
}
//compare between to cars
bool Car::operator==(const Car &car) const {
    return false;
}