/*
 * the class create tcp socket.
 * it create new tcp socket for the client and the server.
 */
#ifndef TCP_H_
#define TCP_H_
#include "Connection.h"
class TCP:public Connection {
protected:

public:
    /*
     * constructor
     */
    TCP(const short unsigned int  &port);

    /*
     * destructor
     */
    virtual ~TCP();
};

#endif /* TCP_H_ */