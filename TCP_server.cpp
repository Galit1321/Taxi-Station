//
// Created by galit on 12/01/17.
//

#include "TCP_server.h"

using namespace std;

/*
 * constructor
 */
TCP_server::TCP_server(const short unsigned int  &port) {
  this->tcp=new Tcp(true,port);
    tcp->initialize();
    socketnum=tcp->socketDescriptor;
}

/*
 * the function get new client and accept it
 */
int TCP_server::getNewClient(){
    int descriptorCommunicateClient;

    return 0;
}

/*
 * the function get message from the client.
 * it get the message,change it to string and return it
 */
std::string TCP_server::getMessage(int client_socket1) {
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
