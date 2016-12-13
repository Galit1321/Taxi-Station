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
public:


    void setCarType(CarType carType);
    double getTariff() const;
    void setTariff(double tariff);
    string getCarType() const;
    Car(int id,string carType ,string manufacturer,string color);

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
    //make one move
   virtual  void  move()=0;
    //compare between two cars
    bool operator==(const Car &car) const;
};


#endif //EX2_CAR_H
