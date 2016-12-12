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
    long rideId;
    int total_dis;
public:
    //return the num of the passengers
    int getNumOfPass() const;
    //add new passenger
    void addPass();
    //return ride id
    long getRideId() const;
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
    SearchableTrip(ILayout* layout1,int start_i,int start_j,int end_i,int end_j);//constructor
    SearchableTrip(ILayout* layout1,int start_i,int start_j,int end_i,int end_j,long rid,int tff);
    Point* getInitialState();//implantation of interface
    Point* getGoalState();//implantation of interface
    queue<Point*> getAllPossibleStates(Point* s);//implamention of interface

};


#endif //ADVPRO1_SEARCHABLETRIP_H