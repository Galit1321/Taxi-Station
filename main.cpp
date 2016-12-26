#include <iostream>
#include "Controller.h"
#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
using namespace std;
int main(int argc,char **argv) {
    Controller* controller=new Controller();
    controller->getCommend();
    delete controller;
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}