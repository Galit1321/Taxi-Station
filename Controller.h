//
// Created by galit on 12/12/16.
//

#ifndef ADVPRO01_CONTROLLER_H
#define ADVPRO01_CONTROLLER_H

#include "Point.h"
#include "TaxiCenter.h"
#include "TCP.h"



class Controller {
    /**
     * class to controller the input in front
     * of the main function
     */
public:
    TaxiCenter *getCenter() const;

public:
    vector<int> client_socket;
    TaxiCenter* center;
    int servertime;
    Connection* connection;
    Controller(const short unsigned int  &port);



    virtual ~Controller();//desrectir
    Controller();//consterctor
    void* getCommend();//busy wating method to get num of commend
protected:
    //commend 9 wait for the right time and make move
    //when the right time comes
    bool CommendNine();
    //commend two that create a new ride
    bool CommendTwo();
    // commend 3 to create a new car with agrument
    bool CommendThree();
    //commend 4 is to get the current position of driver with
    //id given in cin>>id and print it to screen
    bool CommendFour();
    //run all current driver that have a trip to finish point
    bool CommendSix();

    bool runDriver();
    void getNewTrip();
    static void* runClient(void* par);
};

/*
 * struct to hold the menu and the socket number for the client.
 */
struct parameters {
    Controller* c;
    int sockNum;
};

#endif //ADVPRO01_CONTROLLER_H
