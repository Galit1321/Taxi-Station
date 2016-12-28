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
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version);
    // set the start point
    void setPStart(Point *pStart);
    // set the end point
    void setPEnd(Point *pEnd);
    // return the start point
    Point *getPStart() const;
    // return the end point
    Point *getPEnd() const;
    //set the satisfication of the passenger
    void setSatisfaction(float satisfaction);
    //return the satisfication of the passenger
    float  getSatisfaction();

    virtual ~Passenger();
    //constructor
    Passenger(Point *pStart, Point *pEnd);

    //constructor
    Passenger();
};


#endif //EX2_PASSENGER_H
