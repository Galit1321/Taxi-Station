#include <iostream>
#include "Controller.h"
#include <gtest/gtest.h>
using namespace std;
int main(int argc,char **argv) {
    Controller* controller=new Controller();
    controller->getCommend();
    delete controller;
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}