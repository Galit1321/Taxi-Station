//
// Created by michal on 12/3/16.
//

#include "gtest/gtest.h"
#include "../Driver.h"
#include "../Luxury.h"
#include "../TaxiCab.h"
class DriverTest :public ::testing::Test{
/**
  * test class to check DriverTest
  */
public:
    Driver* d1;
    Driver* d2;
    Point* p;
    virtual void SetUp(){
        d1=new Driver(0 ,30,"M", 0);
        d2 =new Driver();
        p=new Point(0,0);
        d1->setCurr_pos(p);
    }

    virtual void TearDown(){
        delete d1;
        delete d2;
        delete p;
    }

    DriverTest(){
    }
};

/**
 * check to see dm call are not failure
 */
TEST_F(DriverTest , Valid){
    ASSERT_NO_FATAL_FAILURE(d1->getCurr_pos());
    ASSERT_NO_FATAL_FAILURE(d1->getCar());
    ASSERT_GT(d1->getId(),-1);
    ASSERT_GE(d1->getSatisfaction(),-1);
    ASSERT_GT(d1->getExperience(),-1);
    ASSERT_GE(d1->getNumOfUser(),-1);

}
/**
 * check to see opertor overlading == works
 */
TEST_F(DriverTest, CheckEqual){
    ASSERT_FALSE(*d1==*d2);
}

/**
 * check to see the statue is valid
 */
TEST_F(DriverTest, DriverTest_SatValid_Test){
    string stat_str="S,M,D,W";
    std::size_t found = stat_str.find(d1->getStat());
    ASSERT_TRUE(found!=std::string::npos);
}
