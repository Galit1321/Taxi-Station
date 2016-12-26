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
    deque<Point*> solution;

public:
    string stat;
    Car *car;
    template <class Archive>
    void Driver::serialize(Archive &ar, const unsigned int version
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
void finishTrip();

    SearchableTrip *getTrip() const;
/**************************need to do****/
    void setTrip(ILayout* layout1,int start_i,int start_j,int end_i,int end_j, int rid, double tff,int numOfPass);
    void move();
    float getSatisfaction();
    void setSatisfaction(float satisfaction);
    deque<Point*> doBFS(SearchableTrip* pEnd);

    virtual ~Driver();
};


#endif //EX2_DRIVER_H
