//
// Created by michal on 12/3/16.
//

#include "gtest/gtest.h"
#include "Passenger.h"

class PassengerTest :public  ::testing::Test{
/**
  * test class to check PassengerTest
  */
public:
    Passenger* pass;
    virtual void SetUp(){

    }

    virtual void TearDown(){
        delete  pass;
    }

    PassengerTest(){
        pass=new Passenger(new Point(0,0), new Point(1,1));
    }


};

/**
 * check to see dm call are not failure
 */
TEST_F(PassengerTest ,valid){
    ASSERT_NO_FATAL_FAILURE(pass->getCurr_pos());

}
/**
 * check to see sastfiaction is between 0 to 5
 */
TEST_F(PassengerTest,PassengerTest_Satisfaction__Test){
    ASSERT_GE(pass->getSatisfaction(),-1.0);
    ASSERT_GT(5.1,pass->getSatisfaction());
}