#include "gtest/gtest.h"
#include "Solution.h"

class SolutionTest : public ::testing::Test {
/**
  * test class to check TaxiCabTest
  */
public:
    Solution *solution;

    void virtual SetUp() {


    }

    void virtual TearDown() {
        delete solution;
    }

    SolutionTest() {
        solution = new Solution();

    }
};


//check the solution is equal
TEST_F(SolutionTest, SolutionTest_S_Test) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            solution->addNode(new Point(i, j));
        }
    }
    ASSERT_EQ(solution->getSol().size(), 25);
}


