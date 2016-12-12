//
// Created by michal on 12/1/16.
//

#include "Passenger.h"

/**
 * constructor
 * @return
 */
Passenger ::Passenger(){
    pStart =NULL;
    pEnd = NULL;
}

//set the satisfication of the passenger
void Passenger ::setSat(int sat) {

}
// return the start point
Point *Passenger::getPStart() const {
    return NULL;
}
// return the end point
Point *Passenger::getPEnd() const {
    return NULL;
}

// set the start point
void Passenger::setPStart(Point *pStart) {
    Passenger::pStart = pStart;
}
// set the end point
void Passenger::setPEnd(Point *pEnd) {
    Passenger::pEnd = pEnd;
}

