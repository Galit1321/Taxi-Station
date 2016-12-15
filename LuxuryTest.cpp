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
 * check to see dm call are not failure
 */
TEST_F(LuxuryTest , ValidMembers){
    ASSERT_NO_FATAL_FAILURE(l->getColor());
    ASSERT_NO_FATAL_FAILURE(l->getManufacturer());
    ASSERT_NO_FATAL_FAILURE(l->move());
    ASSERT_GT(l->getId(),-1);
    ASSERT_GT( l->getMileage(),-1);
    ASSERT_GT( l->getCost(),-1);
}



