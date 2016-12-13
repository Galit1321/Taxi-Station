//
// Created by michal on 12/3/16.
//

#include "string"
#include "gtest/gtest.h"
#include "Luxury.h"
#include "Car.h"
#include "TaxiCab.h"

using namespace std;
class LuxuryTest :public  ::testing::Test{
/**
 * test class to check LuxuryTest
 */
public:
    Luxury* l;
    TaxiCab* t;
    virtual void SetUp(){
        l =new Luxury(0,0,"HONDA","RED",0);
        t = new TaxiCab();
    }

    virtual void TearDown(){
        delete l;
        delete t;
    }

    LuxuryTest(){
    }
};


/**
 * check to see that the tariff of the
 * cabs is not equal
 *
 * /
 *
TEST_F(LuxuryTest , Checktariff){
    ASSERT_NE(l->getCost() , t->getCost());
}*/

/**
 * check to see that the move of luxury is
 * bigger in one step every move
 */
TEST_F(LuxuryTest , CheckSpeed){
    l->move();
    t->move();
    ASSERT_EQ(t->getMileage()+1, l->getMileage());
}

/**
 * check to see dm call are not failure
 */
TEST_F(LuxuryTest , ValidMembers){
    ASSERT_NO_FATAL_FAILURE(l->getColor());
    ASSERT_NO_FATAL_FAILURE(l->getManufacturer());
    ASSERT_NO_FATAL_FAILURE(l->move());
    ASSERT_GT(0, l->getId());
    ASSERT_GT(0, l->getMileage());
    ASSERT_GT(0, l->getCost());
}



