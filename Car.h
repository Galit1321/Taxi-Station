//
// Created by michal on 12/1/16.
//

#include "string"
#include <boost/serialization/access.hpp>
#ifndef EX2_CAR_H
#define EX2_CAR_H

enum  CarType{TAXI=1 ,LUXURY =2};

using namespace std;
class Car {
protected:
    int id ;
    int mileage;
    string color;
    double tariff;
    string manufacturer;
    int kind;
public:
    int getKind() const;

public:
    //set the car type
    void setCarType(CarType carType);
    //get the tariff of the trip
    double getTariff() const;
    //set the tariff of the trip
    void setTariff(double tariff);
    //get the car type
    string getCarType() const;
    //constructor
    Car(int id,int carType ,string manufacturer,string color);
    //constructor
    Car(int id,string manufacturer,string color,int kind);
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
    //selize the object
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version){
        /*
selize*/
            ar& (this->id);
           ar&(this->kind);
           ar&(this->mileage);
            ar&(this->color);
            ar&(this->tariff);
            ar&(this->manufacturer);
        }

    void setKind(int kind);


};


#endif //EX2_CAR_H
