//
// Created by galit on 13/12/16.
//

#ifndef ADVPRO01_CREATERIDE_H
#define ADVPRO01_CREATERIDE_H

/**
 * class CreateRide
 * a class that create a ride
 */

#include "Create.h"

class CreateRide :public  Create{
/**
 * phase the creation of a new ride
 */
public:
    //set the parameters of the ride
    CreateRide(string &input);

    virtual ~CreateRide();
int time;
    int id;
    // the x val of the strat point
    int start_x;
    // the y val of the strat point
    int star_y;
    // the x val of the end point
    int end_x;
    // the y val of the end point
    int end_y;
    // the number of passengers
    int numOfPass;
    //the tariff of the ride
    double tariff;

};


#endif //ADVPRO01_CREATERIDE_H
