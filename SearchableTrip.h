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
/**
 * searchable trip on the matrix
 */
class SearchableTrip : public ISearchable{
private:
    int numOfPass;
    int traiff;
    ILayout* layout;//the layout we do the trip on
    Point* goal;//the goal of the trip
    Point* init;//the start of the trip
    int rideId;
    int total_dis;


public:
    const deque<Point *> &getSolution() const;
    deque<Point*> solution;
    void setSolution(const deque<Point *> &solution);

public:
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version);
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
    SearchableTrip(ILayout* layout1,int start_i,int start_j,int end_i,int end_j, int rid, double tff);

    virtual ~SearchableTrip();

    void setNumOfPass(int numOfPass);

    Point* getInitialState();//implantation of interface
    Point* getGoalState();//implantation of interface
    queue<Point*> getAllPossibleStates(Point* s);//implamention of interface

};


#endif //ADVPRO1_SEARCHABLETRIP_H