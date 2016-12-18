

#include "gtest/gtest.h"
#include "SearchableTrip.h"
#include "MatrixLayout.h"

class SearchableTripTest : public ::testing::Test {
    /**
     * test class to check searchable trip
     */
public:
    SearchableTrip *searchableTrip;

    void virtual SetUp() {

    }

    void virtual TearDown() {
        delete searchableTrip;

    }

    SearchableTripTest() {
        searchableTrip = new SearchableTrip(new MatrixLayout(10, 10), 1, 2, 8, 7);
    }
};
/**
 * check to see dm call are not failure
 */
TEST_F(SearchableTripTest, SearchableTripTest_ValidDataMember_Test) {
    ASSERT_NO_FATAL_FAILURE(searchableTrip->getInitialState());
    ASSERT_NO_FATAL_FAILURE(searchableTrip->getGoalState());

}
/**
 *check to see that if we get invalid i to init point
 * we will get null as init point
 */
TEST_F(SearchableTripTest, SearchableTripTest_CheckOutOfBond_Test) {
    SearchableTrip *st1 = new SearchableTrip(new MatrixLayout(3, 3), 4, 0, 2, 2);
    ASSERT_TRUE(st1->getInitialState() == NULL);
    delete st1;
    SearchableTrip *st2 = new SearchableTrip(new MatrixLayout(3, 3), 0, 0, 20, 2);
    ASSERT_TRUE(st2->getGoalState() == NULL);
    delete st2;

}
/**
 * check to see that in given correct input the goal and init
 * will not be null
 */
TEST_F(SearchableTripTest, SearchableTripTest_CheckInBond__Test) {
    ASSERT_FALSE(searchableTrip->getGoalState() == NULL);
    ASSERT_FALSE(searchableTrip->getInitialState() == NULL);
}
/**
 * check to see that to layput without obstacles we get that we can at least go to 2
 * diff dierctions
 */
TEST_F(SearchableTripTest, SearchableTrip_CheckNoTrapStartnFinish_Test) {
    ASSERT_GT(searchableTrip->getAllPossibleStates(searchableTrip->getInitialState()).size(), 2);
    ASSERT_GT(searchableTrip->getAllPossibleStates(searchableTrip->getGoalState()).size(), 2);
}
/***
 * check to see that with obstacle that dont create init point as dead end
 * searchable.getpossiblestates we get a none empty queue
 */
TEST_F(SearchableTripTest, SearchableTripTest_WithObs_Test) {
    int s[] = {0, 2, 1, 0};
    vector<int> obs(s, s + sizeof(s) / sizeof(int));//we have (0,0) is a deadend
    MatrixLayout *matrix = new MatrixLayout(3, 3, &obs);
    SearchableTrip *st = new SearchableTrip(matrix, 0, 0, 2, 2);
    ASSERT_GT(st->getAllPossibleStates(st->getInitialState()).size(), 0);
    delete st;
    delete matrix;
}

/***
 * check to see that with obstacle so that we created an init point IS a dead end
 * searchable.getpossiblestates will retuen an empty queue
 */
TEST_F(SearchableTripTest, SearchableTripTest_WithObsnDeadEnd_Test) {
    int s[] = {0, 1, 1, 0};
    vector<int> obs(s, s + sizeof(s) / sizeof(int));//we have (0,0) is a deadend
    MatrixLayout *matrix = new MatrixLayout(3, 3, &obs);
    SearchableTrip *st = new SearchableTrip(matrix, 0, 0, 2, 2);
    ASSERT_EQ(st->getAllPossibleStates(st->getInitialState()).size(), 0);
    delete st;
    delete matrix;
}