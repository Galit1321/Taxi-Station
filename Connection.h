/*
 * the class is virtual class (interface) for the sockets.
 * it create new socket,and have send message and get message functions, so the client and the server
 * can use the communications without care what kind of communication they use.
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

class Connection {

protected:

public:
    int socketnum;
    short unsigned int port;

    /*
     * constructor
     */
    Connection(const short unsigned int &port);
    //defult constructor
    Connection();

    /*
     * destructor
     */
    virtual ~Connection();


    /*
     * the function send the message.
     * it get the string message to send and send it.
     */
    virtual void sendMessage (std::string &str, int sock)=0;

    /*
     * the function get the message.
     * it get the message,change it to string and return it
     */
    virtual std::string getMessage (int sock)=0;

    /*
     * the function close the socket
     */
    virtual void closefunc();



};

#endif /* CONNECTION_H_ */

