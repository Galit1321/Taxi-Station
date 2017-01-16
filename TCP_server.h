//
// Created by galit on 12/01/17.
//

#ifndef ADVPRO01_TCP_SERVER_H
#define ADVPRO01_TCP_SERVER_H


#include <list>
#include <string>
#include "Tcp.h"
using namespace std;

class TCP_server {
private:


public:
   Socket* tcp;
    int socketnum;

    /*
     * constructor
     */
    TCP_server(const short unsigned int  &port) ;

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
};

#endif //ADVPRO01_TCP_SERVER_H
