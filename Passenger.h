//
// Created by michal on 12/1/16.
//

#ifndef EX2_PASSENGER_H
#define EX2_PASSENGER_H

#include "Point.h"
#include "Person.h"


class Passenger : public Person{
public:
    Point *pStart ,*pEnd;
    // set the start point
    void setPStart(Point *pStart);
    // set the end point
    void setPEnd(Point *pEnd);
    // return the start point
    Point *getPStart() const;
    // return the end point
    Point *getPEnd() const;
    //set the satisfication of the passenger
    void setSat(int sat);
    //constructor
    Passenger();
};


#endif //EX2_PASSENGER_H
