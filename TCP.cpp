#include "TCP.h"

/*
* constructor
*/
TCP::TCP(const short unsigned int  &port):Connection(port) {
    this->socketnum = socket(AF_INET, SOCK_STREAM, 0);
    if (this->socketnum < 0) {
        perror("error creating socket");
    }
}

/*
 * destructor
 */
TCP::~TCP() {

}

