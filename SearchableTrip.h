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
    int rideId;
    int total_dis;
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

private:
    int traiff;
    ILayout* layout;//the layout we do the trip on
    Point* goal;//the goal of the trip
    Point* init;//the start of the trip
public:
    SearchableTrip();

    ILayout *getLayout() const;

    SearchableTrip(ILayout* layout1,Point* start,Point* end);
    SearchableTrip(ILayout* layout1,int start_i,int start_j,int end_i,int end_j);//constructor
    SearchableTrip(ILayout* layout1,int start_i,int start_j,int end_i,int end_j, int rid, double tff);
    Point* getInitialState();//implantation of interface
    Point* getGoalState();//implantation of interface
    queue<Point*> getAllPossibleStates(Point* s);//implamention of interface

};


#endif //ADVPRO1_SEARCHABLETRIP_H