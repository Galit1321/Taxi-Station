using namespace std;

#include "gtest/gtest.h"
#include "../MatrixLayout.h"


 class MatrixLayoutTest:public ::testing::Test{
 public:
     /**
      * test class to matrix lauout to check
      * all part in this class function proply
      */
MatrixLayout matrixLayout;
     void virtual SetUp(){

     }

     void virtual TearDown(){

     }

MatrixLayoutTest():matrixLayout(10,10){}
 };
/**
 * check that call to all the data members is not
 * fatal and the height and width are positive
 */
TEST_F(MatrixLayoutTest,MatrixLayoutTest_Init_Test){
    ASSERT_NO_FATAL_FAILURE(matrixLayout.getMatrix());
ASSERT_NO_FATAL_FAILURE(matrixLayout.getPNode());
    ASSERT_GT(matrixLayout.getHeight(),0);
    ASSERT_GT(matrixLayout.getWidth(),0);
}
/**
 * check to see if the array init was as plan
 */
TEST_F(MatrixLayoutTest,MatrixLayoutTest_PointArray_Test){
    for (int i=0;i<matrixLayout.getHeight();i++){
        for (int j=0;j<matrixLayout.getWidth();j++){
            ASSERT_TRUE(*matrixLayout.getNode(i,j)==*new Point(i,j));
            ASSERT_EQ(matrixLayout.getMatrix()[i][j],0);
        }
    }
}
/**
 * check to see that from the first row CanGo will return false that we can go
 *  down direction
 */
TEST_F(MatrixLayoutTest,CantGo_firstRow){
    for (int j=0;j<matrixLayout.getWidth();j++){
        ASSERT_FALSE(matrixLayout.canGo(matrixLayout.getNode(0,j),'d'));
    }
}
/**
 * check to see that from the first col CanGo will return false that we can go
 * left direction
 */
TEST_F(MatrixLayoutTest,CantGo_firstCol){
    for (int i=0;i<matrixLayout.getHeight();i++){
        ASSERT_FALSE(matrixLayout.canGo(matrixLayout.getNode(i,0),'l'));
    }
}
/**
 * check to see that from the last col CanGo will return false that we can go
 * in r direction
 */
TEST_F(MatrixLayoutTest,CantGo_lastCol){
    for (int i=0;i<matrixLayout.getHeight();i++){
        ASSERT_FALSE(matrixLayout.canGo(matrixLayout.getNode(i,matrixLayout.getWidth()-1),'r'));
    }
}
/**
 * check to see that from the last row CanGo will return false that we can go
 * up  direction
 */
TEST_F(MatrixLayoutTest,CantGo_lastRow){
    for (int j=0;j<matrixLayout.getHeight();j++){
        ASSERT_FALSE(matrixLayout.canGo(matrixLayout.getNode(matrixLayout.getHeight()-1,j),'u'));
    }
}
/**
 * check to see that for every cell in the matrix
 * canGo will return from every dierction given
 */
TEST_F(MatrixLayoutTest,CANGo){
    for (int i=1;i<matrixLayout.getHeight()-1;i++){
        for (int j=1;j<matrixLayout.getWidth()-1;j++){
            ASSERT_TRUE(matrixLayout.canGo(matrixLayout.getNode(i,j),'u'));
            ASSERT_TRUE(matrixLayout.canGo(matrixLayout.getNode(i,j),'d'));
            ASSERT_TRUE(matrixLayout.canGo(matrixLayout.getNode(i,j),'l'));
            ASSERT_TRUE(matrixLayout.canGo(matrixLayout.getNode(i,j),'r'));
        }}
}
/**
 * check to see that there dead end don't exist in
 * the matrix , dead end=a point which we can't move from to each
 * dierction
 */
TEST_F(MatrixLayoutTest,NoDeadEnd_test){
    int s[]={0,2,1,0};
    vector<int> obs(s,s+sizeof(s)/sizeof(int));//we have (2,2) is a deadend
    MatrixLayout* matrix=new MatrixLayout(3,3,&obs);
    for (int i=0;i<matrix->getHeight();i++){
        for (int j=0;j<matrix->getWidth();j++){
            ASSERT_TRUE((matrix->canGo(matrix->getNode(i,j),'u'))
                         ||(matrix->canGo(matrix->getNode(i,j),'d'))||
                                 (matrix->canGo(matrix->getNode(i,j),'l'))
            ||matrix->canGo(matrix->getNode(i,j),'r'));
        }}
}

