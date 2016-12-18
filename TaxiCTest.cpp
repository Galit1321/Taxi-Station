#include "gtest/gtest.h"
#include "TaxiCenter.h"

class TaxiCTest : public ::testing::Test {
/**
  * test class to check TaxiCabTest
  */
public:
    TaxiCenter* center;

    void virtual SetUp() {

    }

    void virtual TearDown() {
delete center;
    }

    TaxiCTest(){
    center=new TaxiCenter(new MatrixLayout(3,3)) ;

    }
};

/**
 * check to see dm call are not failure
 */
TEST_F(TaxiCTest, TaxiCTest_Valid_Test) {
    ASSERT_NO_FATAL_FAILURE(center->getAll_passngers());
    ASSERT_NO_FATAL_FAILURE(center->getCars());
    ASSERT_NO_FATAL_FAILURE(center->getFree_drivers());
    ASSERT_NO_FATAL_FAILURE(center->getDrivers());
}

/**
 * check the addition of driver
 */
TEST_F(TaxiCTest, addDriverTest) {
    int before = center->getDrivers().size();
    center->addDriver(0,0,"s",0);
   ASSERT_EQ(before + 1, center->getDrivers().size());
}

/**
 * check the creation of taxi
 */
TEST_F(TaxiCTest, TaxiCTest_CreateTaxi_Test) {
    int before = center->getCars().size();
    center->addCar(0,"F","R",1);
    ASSERT_EQ(before + 1, center->getCars().size());
}




/**
 * check to see that we got a driver that was deleted from free driver
 */
TEST_F(TaxiCTest, TaxiCTest_Closer_Test) {
    center->addDriver(0,0,"M",0);
    center->addDriver(1,1,"S",0);
    int driver_id = center->findCloser();
    vector<int>::iterator it;
    it = std::find(center->getFree_drivers().begin(), center->getFree_drivers().end(), driver_id);
    ASSERT_TRUE(it== center->getFree_drivers().end());

}
/**
 * test to see if move is working
 * diff to luxury car to taxi
 */
TEST_F(TaxiCTest, TaxiCTest_TaxiCTestMove_Test_Test){
    center->addCar(0,"F","R",1);
    center->addDriver(0,0,"M",0);
    center->setTaxiToDriver(0,0);
    center->addCar(1,"F","R",2);
    center->addDriver(1,0,"M",0);
    center->setTaxiToDriver(1,1);
    center->getDriver(0)->setTrip(center->getLayout(),0,0,2,2,0,1.0,5);
    center->move(0);
    center->getDriver(1)->setTrip(center->getLayout(),0,0,2,2,2,1.0,5);
    center->move(1);
    ASSERT_GT(center->getCars()[1]->getMileage(),center->getCars()[0]->getMileage());
}
/**
 * check to see the finsih trip works;
 */
TEST_F(TaxiCTest, TaxiCTest_TaxiCenterFinishTrip_Test){
    center->addCar(0,"F","R",1);
    center->addDriver(0,0,"M",0);
    center->setTaxiToDriver(0,0);
    center->getDriver(0)->setTrip(center->getLayout(),0,0,2,2,0,1.0,5);
    center->finishAllTrip();
    ASSERT_EQ(center->getDriver(0)->getTrip()->getGoalState()->getI(),2);
    ASSERT_EQ(center->getDriver(0)->getTrip()->getGoalState()->getJ(),2);
}