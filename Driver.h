//
// Created by michal on 12/1/16.
//

#ifndef EX2_DRIVER_H
#define EX2_DRIVER_H

#include "string"
#include "TaxiCab.h"
#include "Point.h"
#include "Solution.h"
#include "Person.h"
#include "SearchableTrip.h"

class Driver :public Person{
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
    //set the driver id
    void setId(int id);
    //set the driver age
    void setAge(int age);
    //set the status of the driver
    void setStat(string stat);
    //set the car of the driver
    void setCar(Car *car);
    //set the years of experience of the driver
    void setExperience(int experience);
    //set the num of the users
    void setNumOfUser(int numOfUser);
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
    int getDistance(Point point);
    //run the bfs algoritm
    Solution* doBFS(Point pEnd);

    SearchableTrip *getTrip() const;

    void setTrip(SearchableTrip *trip);
};


#endif //EX2_DRIVER_H
