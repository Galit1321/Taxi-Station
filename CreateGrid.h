

#ifndef ADVPRO1_CREATEGRID_H
#define ADVPRO1_CREATEGRID_H

#include <iostream>
#include "Create.h"
#include "vector"
using namespace std;
/**
 *  create a grid by the token given to it
 *  extend the Create class
 *  becuase it is a grid we will look for sizes of grid
 *  in case of diffrent grid (that is not matrix)
 *  we just add to constructor to check
 */
class CreateGrid:public Create{

public:
vector<int> input;
    CreateGrid(string &input);//constructor
    virtual ~CreateGrid();//deconstructor
    //divide the input
    void phase(string s);
    //return the params from theinput in a vector
     vector<int> &getInput() ;

};


#endif //ADVPRO1_CREATEGRID_H