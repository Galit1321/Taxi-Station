//
// Created by galit on 12/12/16.
//

#ifndef ADVPRO01_CONTROLLER_H
#define ADVPRO01_CONTROLLER_H

#include "Point.h"
#include "TaxiCenter.h"
#include "UDP.h"



class Controller: public UDP {
    /**
     * class to controller the input in front
     * of the main function
     */
public:
    vector<int> client_socket;
    TaxiCenter* center;
    int servertime;

    Controller(const short unsigned int  &port);
   /*
    * the function send message for the client.
    * it get the string message to send and send it.
    */
    void sendMessage (std::string &str, int sock);

    /*
     * the function get message from the client.
     * it get the message,change it to string and return it
     */
    string getMessage (int sock);

    /*
     * the function get new client and accept it
     */
    void getNewClient();
    static void* staticForChose(void* parameters);

    virtual ~Controller();//desrectir
    Controller();//consterctor
    void* getCommend();//busy wating method to get num of commend
protected:
    bool CommendNine();
    bool CommendTwo();
    bool CommendThree();
    bool CommendFour();
    bool CommendSix();
    bool runDriver();
    void getNewTrip();
};

/*
 * struct to hold the menu and the socket number for the client.
 */
struct parameters {
    Controller* m;
};

#endif //ADVPRO01_CONTROLLER_H
