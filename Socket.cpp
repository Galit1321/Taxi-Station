/************************************************************
* File description: Socket class. creating socket, close 	*
* socket and method prints the errors occurs while			*
* creating sockets, in all the different methods involved	*
************************************************************/

#include "Socket.h"
#include <unistd.h>



#define NONE 0

/***********************************************************************
* function name: Socket												   *
* The Input: none													   *
* The output: none										               *
* The Function operation: creating new Socket object, with the computer*
* ip, and no port number and socket descriptor, 0 backlogs.			   *
***********************************************************************/
Socket::Socket() {
	this->ip_address = IP;
	this->backLog = NONE;
	this->socketDescriptor = NONE;
	this->isServer = true;
	this->port_number = NONE;
}

/***********************************************************************
* function name: ~Socket											   *
* The Input: none													   *
* The output: none										               *
* The Function operation: default destructor					       *
***********************************************************************/
Socket::~Socket() {
	close(this->socketDescriptor);
}
/***********************************************************************
* function name: getNewClient	`										*
* The Input: none										                *
* The output: int number representing the descriptor Communicate Client *
* The Function operation: getting data from the other socket
***********************************************************************/
int Socket::getNewClient(){
	//accept
	struct sockaddr_in client_sin;
	unsigned int addr_len = sizeof(client_sin);
	int descriptorCommunicateClient = accept(this->socketDescriptor,
											   (struct sockaddr *) &client_sin, &addr_len);
	if (descriptorCommunicateClient < 0) {
		//return an error represent error at this method
		return ERROR_ACCEPT;
	}
	else {
		return descriptorCommunicateClient;
	}
}

