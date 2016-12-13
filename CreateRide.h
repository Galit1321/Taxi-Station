//
// Created by galit on 13/12/16.
//

#ifndef ADVPRO01_CREATERIDE_H
#define ADVPRO01_CREATERIDE_H

#include "Create.h"
#include "SearchableTrip.h"
class CreateRide :public  Create{

public:
    CreateRide(string &input);
    SearchableTrip* getTrip();

    virtual ~CreateRide();
    void phase(string s);
    int id;
    int start_x;
    int star_y;
    int end_x;
    int end_y;
    int numOfPass;
    double tariff;

};


#endif //ADVPRO01_CREATERIDE_H
