//
// Created by michal on 12/1/16.
//

#ifndef EX2_DRIVER_H
#define EX2_DRIVER_H


#include "string"
#include "Car.h"
#include "Point.h"
#include "Person.h"
#include "SearchableTrip.h"
#include "BFS.h"
#include <boost/serialization/access.hpp>

class Driver :public Person{
    /**
     * class of driver of the cab
     */
private:
   int id;
    int age;
    int experience;
    int numOfUser;
    SearchableTrip* trip;


public:
    string stat;
    Car *car;


    Driver();//default constructor
    Driver(Driver &object);//copy constructor
    Driver(int id ,int age,string stat , int experience);//constructor

    //set the car of the driver
    void setCar(Car *car);

    //return the status of the driver
    string getStat() const;
    //return the car of the driver
    Car *getCar() const;
    //return the driver id
    int getId() const;
    //return the driver age
    int getAge() const;
    //return the years of experience of the driver
    int getExperience() const;
    //return the num of the users
    int getNumOfUser() const;

    //compare between 2 drivers
    bool operator==(const Driver &driver1)const ;
    //find the distance from the driver curr pose
    //to the given point
void finishTrip();

    SearchableTrip *getTrip() const;
    void setTrip(SearchableTrip* trip1);
    void move();
    float getSatisfaction();
    void setSatisfaction(float satisfaction);

//serlize the driver

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version){
        ar & boost::serialization::base_object<Person>(*this);
        ar & stat;
        ar & id;
        ar & age;
        ar & experience;
        ar & numOfUser;
    }
    virtual ~Driver();
};


#endif //EX2_DRIVER_H
