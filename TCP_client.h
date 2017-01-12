//
// Created by galit on 12/01/17.
//

#ifndef ADVPRO01_TCP_CLIENT_H
#define ADVPRO01_TCP_CLIENT_H

#include "TCP.h"
class TCP_client: public TCP{
public:
    TCP_client(const unsigned short &port,const char* ip);

    virtual ~TCP_client();
     const char* ip;
	 /* the function send message for the server.
	 * it get the string message to send and send it.
	 */
    void sendMessage (std::string &str);

    /*
     * the function get message from the server.
     * it get the message,change it to string and return it
     */
    std::string getMessage ();

};


#endif //ADVPRO01_TCP_CLIENT_H
