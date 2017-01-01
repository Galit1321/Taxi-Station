#include "UDP.h"

/*
 * constructor
 * create the socket and connect to the port
 */

UDP::UDP(const short unsigned int  &port):Connection(port) {
    this->socketnum =socket(AF_INET, SOCK_DGRAM, 0);
    if (socketnum < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(this->port);
    //bind
    if (::bind(socketnum, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding to socket");
    }
}

/**
 * send msg in sock with given id
 * @param str what we want to send
 * @param id socket id -more relavent to tcp
 */
void UDP::sendMessage(std::string &str, int size) {
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    string ip_address="127.0.0.1";
    sin.sin_addr.s_addr = inet_addr(ip_address.c_str());
    sin.sin_port = htons(this->port);
    const char * datas = str.c_str();
    int data_len = str.length() + 1;
    //send
    int sent_bytes = sendto(this->socketnum,datas, data_len, 0, (struct sockaddr *) &sin, sizeof(sin));
//	cout << sent_bytes << endl;
    //check if send successfully
    if (sent_bytes < 0) {
        return perror("client error ");
    }
}

/**'
 *
 * wait to get messege from socket
 * @param id socket id
 * @return the string of want we got
 */
std::string UDP::getMessage(int s) {
    struct sockaddr_in to;
    char buffer[4050];
    unsigned int to_len = sizeof(struct sockaddr_in);
    //receive
    int bytes = recvfrom(this->socketnum,
                         buffer, sizeof(buffer) , 0, (struct sockaddr *) &to, &to_len);
    //set the port number to the new one which we get with the data
    this->port = ntohs(to.sin_port);
    //check if receive successfully

//    cout << bytes << endl;
    if (bytes < 0) {
        perror("fail to rec data");
    }
    string str(buffer, sizeof(buffer));
    return str;
}

/*
 * destructor
 */
UDP::~UDP() {
    close(socketnum);
}

/*
 * defult constructor
 */
UDP::UDP():Connection() {

}