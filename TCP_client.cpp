//
// Created by galit on 12/01/17.
//

#include "TCP_client.h"

TCP_client::TCP_client(const unsigned short &port,const char* ip) : TCP(port) {
    this->ip = ip;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(this->ip);
    sin.sin_port = htons(this->port);

    if (connect(this->socketnum, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
}
}

TCP_client::~TCP_client() {

}