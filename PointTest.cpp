//
// Created by galit on 30/11/16.
//

#include "gtest/gtest.h"

#include "Point.h"
class PointTest: public ::testing::Test{
public:
    Point point;

    PointTest():point(0,0){
        point.setParent(new Point(1,0));
    }

    virtual void SetUp(){

    }
    virtual void TearDown(){

    }

};
/**
 * check to see that == oveloadind works
 */
TEST_F(PointTest,PointTest_Santiy_Test){
    ASSERT_EQ(Point(0,0),point);
}
/**
 * check to see if < overloading works
 */
TEST_F(PointTest,isgreater){
    ASSERT_GT(point,Point(3,3));
}
/**
 * check to see that there is not loop with himself
 */
TEST_F(PointTest,Parenty_test){
    if(point.getParent()!=NULL)
    {Point v=*point.getParent();
    ASSERT_FALSE(point==v);
    }
}
/*
 *check to see if the print is as instructed
 */
TEST_F(PointTest,print_test){
    stringstream buffer;
    buffer<<point;
    ASSERT_EQ("(0,0)\n",buffer.str());
}
