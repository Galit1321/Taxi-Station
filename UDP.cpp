#include "UDP.h"


UDP::UDP(const short unsigned int  &port):Connection(port) {
    this->socketnum =socket(AF_INET, SOCK_DGRAM, 0);
    if (socketnum < 0) {
        perror("error creating socket");
    }
}

/*
 * destructor
 */
UDP::~UDP() {
}