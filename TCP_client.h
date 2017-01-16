//
// Created by galit on 12/01/17.
//

#ifndef ADVPRO01_TCP_CLIENT_H
#define ADVPRO01_TCP_CLIENT_H

#include "Driver.h"
#include "TCP.h"
class TCP_client: public TCP{
public:
    TCP_client(const unsigned short &port,const char* ip);
    struct sockaddr_in connection_details;
   // int client_socket;
    virtual ~TCP_client();
    const char* ip;
    int time;
    Driver *driver;

    Driver *getDriver() const;
    void setNewTrip();
    void setDriver(Driver *driver);
    void move();
    /* the function send message for the server.
    * it get the string message to send and send it.
    */
    void sendMessage (std::string &str, int sock);
    void runDriver();

    /*
     * the function get message from the client.
     * it get the message,change it to string and return it
     */
    std::string getMessage (int sock);

};


#endif //ADVPRO01_TCP_CLIENT_H
