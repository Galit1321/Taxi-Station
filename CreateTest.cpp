#include "gtest/gtest.h"
#include "CreateGrid.h"
#include "vector"
class CreateTest :public  ::testing::Test{
public:
    CreateGrid* cg;
    virtual void SetUp(){


    }

    virtual void TearDown(){
        delete  cg;
    }

    CreateTest(){
        string g="9,9,0,8,7,0";
        cg=new CreateGrid(g);
    }
};
/**
 * check to if the input was not empty and token list\
 * was created and the input
 */
TEST_F(CreateTest,Valid){

    ASSERT_NO_FATAL_FAILURE(cg->getTokens().size());


}

/**
 * check to see if format error accure
 * meaning that
 */
TEST_F(CreateTest,CreateTest_FormatError_Test){
    list<string> h;
    cg->getTokens().swap(h);
    ASSERT_NO_FATAL_FAILURE(cg->getTokens().begin());//s
   /* for (std::list<string>::const_iterator it=h.begin(); it !=h.end(); ++it){
        string s=*it;
        ASSERT_TRUE(s.find(",") != std::string::npos);
    }*/
}
/**
 * check to see if all point given to us are
 * greater or eq  to 0
 */

//TEST_F(CreateTest,InputPostive){
//    vector<int> tmp= cg->getInput();
//    for (vector<int>::iterator iter=tmp->begin();iter!=tmp->end();iter++){
//        ASSERT_GT(*iter,-1);
//    }
//}