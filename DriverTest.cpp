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
        d1=new Driver(323,22,"M",5);
        d2 =new Driver(323,22,"M",5);
        p=new Point(0,0);
        d1->setCurr_pos(p);
    }

    virtual void TearDown(){
        delete d1;
        delete d2;
        //delete p;
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
  //  ASSERT_NO_FATAL_FAILURE(d1->doBFS(p));
  //  ASSERT_NO_FATAL_FAILURE(d1->move());
    ASSERT_GT(d1->getId(),0);
    //ASSERT_GE(d1->getSatisfaction(),0);
    ASSERT_GT(d1->getExperience(),0);
   // ASSERT_GE(d1->getNumOfUser(),0);

}

TEST_F(DriverTest, CheckEqual){
    ASSERT_NO_FATAL_FAILURE(d1->operator==(*d2));
}

TEST_F(DriverTest, CheckFinish){
    ASSERT_NO_FATAL_FAILURE(d1->finishTrip());
}

TEST_F(DriverTest, checkRandomSat){
    d1->setStat();
    ASSERT_GT(0,d1->getSatisfaction());
   // ASSERT_LT(d1->getSatisfaction(),6);
}