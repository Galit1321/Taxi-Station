//
// Created by michal on 12/3/16.
//

#include "gtest/gtest.h"
#include "TaxiCab.h"

class TaxiCabTest :public::testing::Test{
/**
  * test class to check TaxiCabTest
  */
public:
    TaxiCab* c;
    virtual void SetUp(){
        c=new TaxiCab();
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
    ASSERT_NO_FATAL_FAILURE(c->move());
    ASSERT_GT(c->getId(),0);
    ASSERT_GT(c->getMileage(),0);
    ASSERT_GT(c->getCost(),0);
}


