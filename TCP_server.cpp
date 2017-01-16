//
// Created by galit on 12/01/17.
//

#include "TCP_server.h"

using namespace std;

/*
 * constructor
 */
TCP_server::TCP_server(const short unsigned int  &port):TCP(port) {
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(this->port);
    //bind
    if (bind(this->socketnum,
             (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        //return an error represent error at this method
        perror("error binding socket");
    }
    //listen
    if (listen(this->socketnum, 5) < 0) {
        //return an error represent error at this method
        perror("error listening to a socket");
    }

}

/*
 * the function get new client and accept it
 */
int TCP_server::getNewClient() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    this->client_socket = accept(this->socketnum,  (struct sockaddr *) &client_sin,  &addr_len);
    if (client_socket < 0) {
        perror("error accepting client");
    }
    return this->client_socket;
}

/*
 * the function get message from the client.
 * it get the message,change it to string and return it
 */
std::string TCP_server::getMessage (int client_socket1 ) {
    char buffer[4096] = {0};
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_socket1, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        perror("connection is closed");
    }
    else if (read_bytes < 0) {
        perror("error");
    }
    return buffer;
}

/*
 * the function send message for the client.
 * it get the string message to send and send it.
 */
void TCP_server::sendMessage (std::string &str, int client_socket1) {
    int sent_bytes = send(client_socket1, str.c_str(), str.length(), 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}
