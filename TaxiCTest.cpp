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
    center=new TaxiCenter() ;

    }
};

/**
 * check to see dm call are not failure
 */
TEST_F(TaxiCTest, TaxiCTest_Valid_Test) {
    ASSERT_NO_FATAL_FAILURE(center->getAll_passngers());
    ASSERT_NO_FATAL_FAILURE(center->getCars());
    ASSERT_NO_FATAL_FAILURE(center->getFree_drivers());
    ASSERT_NO_FATAL_FAILURE(center->getLocations());
    ASSERT_NO_FATAL_FAILURE(center->getDrivers());
}

/**
 * check the addition of driver
 */
TEST_F(TaxiCTest, addDriverTest) {
    int before = center->getDrivers().size();
    center->addDriver(new Driver());
    ASSERT_EQ(before + 1, center->getDrivers().size());
}

/**
 * check the creation of taxi
 */
TEST_F(TaxiCTest, TaxiCTest_CreateTaxi_Test) {
    int before = center->getCars().size();
    center->createTaxi("");
    ASSERT_EQ(before + 1, center->getCars().size());
}

/**
 * check the priting of the location
 */
TEST_F(TaxiCTest, printLocation_test) {
    ASSERT_GT(center->printLocation(0).size(), 0);
}

/**
 * check the get location test
 */
TEST_F(TaxiCTest, getLoc_test) {
    Point *point = center->getLocation(0);
    ASSERT_FALSE(point == NULL);

}


TEST_F(TaxiCTest, TaxiCTest_Closer_Test) {
    Driver *driver = center->findCloser(new Point(0, 0));
    vector<int>::iterator it;
    it = std::find(center->getFree_drivers().begin(), center->getFree_drivers().end(), driver->getId());
    ASSERT_TRUE(it != center->getFree_drivers().end());
    delete driver;
}
