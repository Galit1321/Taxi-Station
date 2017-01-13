
#include "Connection.h"
/*
* constructor
*/
Connection::Connection(const short unsigned int& port) {
    this->socketnum = 0;
    this->port = port;
}

/*
 * destructor
 */
Connection::~Connection() {
    close(socketnum);
}

/*
* defult constructor
*/
Connection::Connection() {

}

int Connection::getNewClient() {
    return socketnum;
}