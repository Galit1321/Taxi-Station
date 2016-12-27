//
// Created by michal on 12/1/16.
//

#ifndef EX2_PERSON_H
#define EX2_PERSON_H

#include "Point.h"
#include <boost/serialization/access.hpp>

class Person {
public:
    Person();//constructor
    double satisfaction;//the satisfaction of the passenger
    Point *curr_pos;//the curr pose of the passenger
    //return the satisfaction of the passenger
    virtual float getSatisfaction()=0;
    //get the curr pose of the passenger
    Point *getCurr_pos() const;
    //set the satisfaction of the passenger
    virtual void setSatisfaction(float satisfaction)=0;
    //set the curr pose of the passenger
    void setCurr_pos(Point *curr_pos);
    virtual ~ Person();//deconstructor


protected:

    Point* getPose();
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version){
        ar & satisfaction;
        ar & curr_pos;
    }
};


#endif //EX2_PERSON_H
