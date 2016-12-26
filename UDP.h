#ifndef SRC1_UDP_H_
#define SRC1_UDP_H_

#include "Connection.h"

class UDP: public Connection {
protected:
    struct sockaddr_in sin;
public:
    UDP(const short unsigned int  &port);
    virtual ~UDP();

};

#endif /* SRC1_UDP_H_ */