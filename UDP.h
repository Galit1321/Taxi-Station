#ifndef SRC1_UDP_H_
#define SRC1_UDP_H_

#include <boost/serialization/access.hpp>
#include "Connection.h"

class UDP: public Connection {
protected:

public:
    UDP(const short unsigned int  &port);

    UDP();

    virtual ~UDP();

};

#endif /* SRC1_UDP_H_ */

