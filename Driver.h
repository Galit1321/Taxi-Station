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

 enum class status{MARRIED = 0, SINGLE =1, DIVORCED =2, WIDOWED =3};

class Driver :public Person{
private:
    long id;
    int age;

private:
    int experience;
    int numOfUser;
public:
    status stat;
    TaxiCab *car;
    Driver();//default constructor
    Driver(Driver &object);//copy constructor
    Driver(long id ,int age , int experience ,status stat );//constructor
    //set the driver id
    void setId(long id);
    //set the driver age
    void setAge(int age);
    //set the status of the driver
    void setStat(status stat);
    //set the car of the driver
    void setCar(TaxiCab *car);
    //set the years of experience of the driver
    void setExperience(int experience);
    //set the num of the users
    void setNumOfUser(int numOfUser);
    //return the status of the driver
    status getStat() const;
    //return the car of the driver
    TaxiCab *getCar() const;
    //return the driver id
    long getId() const;
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
};


#endif //EX2_DRIVER_H
