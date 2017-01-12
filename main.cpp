#include <iostream>
#include "Controller.h"

using namespace std;
int mainclient(int argc,char **argv) {
        int port=atoi(argv[1]);
    Controller* controller=new Controller(port);
    controller->getCommend();
    delete controller;
    return 0;
}
