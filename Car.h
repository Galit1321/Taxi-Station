//
// Created by michal on 12/1/16.
//

#include "string"
#include "Solution.h"
#ifndef EX2_CAR_H
#define EX2_CAR_H

enum  CarType{TAXI=1 ,LUXURY =2};

using namespace std;
class Car {
protected:
    int id ;
    int mileage;
    string color;
    string carType;
    double tariff;
    string manufacturer;
    int kind;
public:
    int getKind() const;

    void setKind(int kind);

protected:
    int speed;


public:
    //get the type of the car
    void setCarType(CarType carType);
    //get the tariff of the trip
    double getTariff() const;
    //get the tariff of the trip
    void setTariff(double tariff);
    //get the type of the car
    string getCarType() const;
    Car(int id,string carType ,string manufacturer,string color);
    Car(int id,string carType ,string manufacturer,string color,int kind);
    //defult constructor
    Car();
    //set the id of the car
    void setId(int id);
    // return the mileage that have passed
    void setMileage(int mileage);
    void setColor(string color);
    // set the manufacture of the car
    void setManufacturer(string manufacturer);
    //return the id of the car
    int getId() const;
    // get the mileage of the car
    int getMileage() const;
    // get the color of the car
    string getColor() const;
    // get the manufacture of the car
    string getManufacturer() const;
    //compare between two cars
    bool operator==(const Car &car) const;
};


#endif //EX2_CAR_H
