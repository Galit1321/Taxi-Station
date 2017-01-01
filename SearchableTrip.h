//
// Created by galit on 22/11/16.
//

#ifndef ADVPRO1_SEARCHABLETRIP_H
#define ADVPRO1_SEARCHABLETRIP_H

using namespace std;
#include "ILayout.h"
#include "list"
#include "Point.h"
#include "ISearchable.h"
#include <boost/serialization/map.hpp>
#include <boost/serialization/deque.hpp>
#include <boost/ref.hpp>


/**
 * searchable trip on the matrix
 */
class SearchableTrip : public ISearchable{
private:
    int numOfPass;// the number of passengers
    int traiff;//the taarif of the trip
    ILayout* layout;//the layout we do the trip on
    Point* goal;//the goal of the trip
    Point* init;//the start of the trip
    int rideId;//the id of the trip
    int total_dis;//the distance of the trip
    int time;// the time of the trip
public:
    //return the time of the trip
    int getTime() const;
    //set the time of the trip
    void setTime(int time);


public:
    //return the solution of the trip
    const deque<Point *> &getSolution() const;
    deque<Point*> solution;
    //set the olution of the trip
    void setSolution(const deque<Point *> &solution);

public:

    //return the num of the passengers
    int getNumOfPass() const;
    //add new passenger
    void addPass();
    //return ride id
    int getRideId() const;
    //return the total distance
    int getTotal_dis() const;
    //set the total distance
    void setTotal_dis(int total_dis);
    //return the tariff
    int getTraiff() const;
    //set the tariff
    void setTraiff(int traiff);


public:
    SearchableTrip();//defult constructor

    ILayout *getLayout() const;//get a layout
void clean(list<Point> closed);
    SearchableTrip(ILayout* layout1,Point* start,Point* end);//constructor
    SearchableTrip(ILayout* layout1,int start_i,int start_j,int end_i,int end_j);//constructor
    //constructor
    SearchableTrip(ILayout* layout1,int start_i,int start_j,int end_i,int end_j, int rid, double tff,int nop);

    virtual ~SearchableTrip();
    //set the number of passengers
    void setNumOfPass(int numOfPass);

    Point* getInitialState();//implantation of interface
    Point* getGoalState();//implantation of interface
    queue<Point*> getAllPossibleStates(Point* s);//implamention of interface
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version){
        /*
selize*/
        ar & boost::serialization::base_object<ISearchable>(*this);
        ar& (this->rideId);
        ar&(this->init);
        ar&(this->goal);
        ar&(this->numOfPass);

       ar&(this->solution);
    }
};


#endif //ADVPRO1_SEARCHABLETRIP_H