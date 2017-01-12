#ifndef SRC1_UDP_H_
#define SRC1_UDP_H_

#include <boost/serialization/access.hpp>
#include "Connection.h"
#include <string.h>
using namespace std;
class UDP: public Connection {
protected:

public:
    //constructor
    UDP(const short unsigned int  &port);
    //defult constructor
    UDP();

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


    //deconstructor
    virtual ~UDP();

};

#endif /* SRC1_UDP_H_ */

