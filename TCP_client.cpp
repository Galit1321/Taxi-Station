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

/*
 * the function send message for the server.
 * it get the string message to send and send it.
 */
void TCP_client::sendMessage (std::string &str,int sock) {
    int sent_bytes = send(this->socketnum, str.c_str(), str.length(), 0);
    if (sent_bytes < 0) {
        perror("error");
    }
}

/*
 * the function get message from the server.
 * it get the message,change it to string and return it
 */
std::string TCP_client::getMessage (int sock) {
    char buffer[4096] = {0};
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(this->socketnum, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        perror("connection is closed");
    }
    else if (read_bytes < 0) {
        perror("error");
    }
    return buffer;
}