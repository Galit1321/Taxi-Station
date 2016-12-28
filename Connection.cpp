//
// Created by galit on 26/12/16.
//

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
}

/*
 * the function close the socket
 */
void Connection::closefunc() {
    close(socketnum);
}
Connection::Connection() {

}