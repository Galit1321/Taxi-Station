#include <iostream>
#include "udp_client.h"

using namespace std;
int main(int argc,char **argv) {
    int port = atoi(argv[2]);
    char* array  = argv[1];
    udp_client *client1 = new udp_client(port, array);
    client1->runDriver();

    delete client1;
}