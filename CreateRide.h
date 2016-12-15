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
#include "SearchableTrip.h"
class CreateRide :public  Create{

public:
    //set the parameters of the ride
    CreateRide(string &input);
    SearchableTrip* getTrip();

    virtual ~CreateRide();
    void phase(string s);
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
