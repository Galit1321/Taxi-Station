//
// Created by galit on 12/12/16.
//

#ifndef ADVPRO01_CONTROLLER_H
#define ADVPRO01_CONTROLLER_H

#include "Point.h"
#include "TaxiCenter.h"
using namespace std;

class Controller {
    /**
     * class to controller the input in front
     * of the main function
     */
public:
    list<int> client_socket;
    TaxiCenter* center;
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
    std::string getMessage (int sock);

    /*
     * the function get new client and accept it
     */
    int getNewClient();

    /*
     * the function get socket number for the client and change it
     */
    void setClientSocketNum(int sockNum);
    virtual ~Controller();//desrectir
    Controller();//consterctor
    void getCommend();//busy wating method to get num of commend
protected:
    bool CommendOne();
    bool CommendTwo();
    bool CommendThree();
    bool CommendFour();
    bool CommendSix();
};


#endif //ADVPRO01_CONTROLLER_H
