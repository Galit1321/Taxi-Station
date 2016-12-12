//
// Created by michal on 12/3/16.
//

#include "gtest/gtest.h"
#include "Driver.h"

class DriverTest :public ::testing::Test{
/**
  * test class to check DriverTest
  */
public:
    Driver* d1;
    Driver* d2;
    Point* p;
    virtual void SetUp(){
        d1=new Driver();
        d2 =new Driver();
        p=new Point(0,0);
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
    ASSERT_NO_FATAL_FAILURE(d1->doBFS(*p));
    ASSERT_GE(d1->getDistance(*p),0);
    ASSERT_GT(d1->getId(),0);
    ASSERT_GE(d1->getSatisfaction(),0);
    ASSERT_GT(d1->getExperience(),0);
    ASSERT_GE(d1->getNumOfUser(),0);

}

TEST_F(DriverTest, CheckEqual){
   // ASSERT_EQ(1. d1->operator==());
}

