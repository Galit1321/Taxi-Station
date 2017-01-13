
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
 * the function close the socket
 */
void Connection::closefunc() {

}

/*
* defult constructor
*/
Connection::Connection() {

}