

#include "gtest/gtest.h"
#include "BFS.h"
#include "SearchableTrip.h"
#include "MatrixLayout.h"

using namespace std;
class BFSTest :public ::testing::Test{

/**
     * testing class to bfs that check to
     * see if the search method in bfs was
     * actived on valid input and the solution given is valid
     */

public:
    SearchableTrip* searchableTrip;
    BFS bfs;

    virtual void SetUp(){

        searchableTrip=new SearchableTrip(new MatrixLayout(10,10),0,0,9,1);

    }

/*
     * tear down that will act as descructor
     */

    virtual void TearDown(){
        delete  searchableTrip;
    }

   BFSTest():bfs(){

   }

};

/**
 * check to see if we got a sol to the point we check
 */

TEST_F(BFSTest,SearchSize){
   deque<Point*> s=bfs.search(searchableTrip);
   ASSERT_GT(s.size(),0);
}

/**
 * check to see if what we need for bfs.search are
 * valid reqest and will not cause exception
 */

TEST_F(BFSTest,SolNull){
   deque<Point*> s=bfs.search(searchableTrip);
    ASSERT_NO_FATAL_FAILURE(searchableTrip->getGoalState());
    ASSERT_NO_FATAL_FAILURE(searchableTrip->getInitialState());
    ASSERT_NO_FATAL_FAILURE(s.size());


}

/**
 * test that will see if we have duplicate point in
 * our solution, if a point apper more than
 * once it show that this is not
 * shotrest path
 */

TEST_F(BFSTest,UniqeTest) {
   deque<Point*> s=bfs.search(searchableTrip);
    int size = s.size();
    list<Point> g;
    while (!s.empty()) {
        Point* p = s.front();
        if (std::find(g.begin(),g.end(),*p)==g.end())
        g.push_back(*p);
        s.pop_front();
    }
   ASSERT_EQ(g.size(), size);
    s.clear();
}
/**
 * check to see that even with obstacles we can still search
 */

TEST_F(BFSTest,BFSTest_SearchWithOb_Test){
    int s[] = {0, 2, 1, 0,0,2};
    vector<int> obs(s, s + sizeof(s) / sizeof(int));//we have (0,0) is a deadend
    MatrixLayout *matrix = new MatrixLayout(3, 3, &obs);
    SearchableTrip *st = new SearchableTrip(matrix, 0, 0, 2, 2);
    deque<Point*> solution=bfs.search(st);
    ASSERT_GT(solution.size(),0);
    solution.clear();
    delete  matrix;
    delete st;
}

