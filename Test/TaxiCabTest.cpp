//
// Created by michal on 12/3/16.
//

#include "gtest/gtest.h"
#include "../TaxiCab.h"

class TaxiCabTest :public::testing::Test{
/**
  * test class to check TaxiCabTest
  */
public:
    TaxiCab* c;
    virtual void SetUp(){
        c=new TaxiCab(0,0,"F","R",1);
    }

    virtual void TearDown(){
        delete  c;
    }

    TaxiCabTest(){
    }
};

/**
 * check to see dm call are not failure
 */
TEST_F(TaxiCabTest , ValidMembers){
    ASSERT_NO_FATAL_FAILURE(c->getColor());
    ASSERT_NO_FATAL_FAILURE(c->getManufacturer());
    ASSERT_GT(c->getId(),-1);
    ASSERT_GT(c->getMileage(),-1);
    ASSERT_GT(c->getCost(),-1);
}
/**
 * check to see the the manufactor is a valid one
 */

TEST_F(TaxiCabTest , TaxiCabTest_ValidManufactor_Test){
    string manStr="H,S,T,F";
    std::size_t found = manStr.find(c->getManufacturer());
  ASSERT_TRUE(found!=std::string::npos);
}
/**
 * see that we have valid color
 */
TEST_F(TaxiCabTest , TaxiCabTest_ValidColor_Test){
    string manStr="R,B,G,P,W";
    std::size_t found = manStr.find(c->getColor());
    ASSERT_TRUE(found!=std::string::npos);
}
