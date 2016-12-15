//
// Created by michal on 12/1/16.
//
#include <stdlib.h>
#include "Passenger.h"

/**
 * constructor
 * @return
 */
Passenger ::Passenger(){
    pStart =NULL;
    pEnd = NULL;
}

// return the start point
Point *Passenger::getPStart() const {
    return pStart;
}
// return the end point
Point *Passenger::getPEnd() const {
    return pEnd;
}

// set the start point
void Passenger::setPStart(Point *pStart) {
    Passenger::pStart = pStart;
}
// set the end point
void Passenger::setPEnd(Point *pEnd) {
    Passenger::pEnd = pEnd;
}
/***
 * generate a random float point betwwen 0 to 5
 * @return the passenger satisfaction
 */
float Passenger::getSatisfaction() {
   this->satisfaction=static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/5));
}
void Passenger::setSatisfaction(float satisfaction) {

}
