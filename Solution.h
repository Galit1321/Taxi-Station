//
// Created by galit on 14/11/16.
//

#ifndef ADVPRO1_SOLUTION_H
#define ADVPRO1_SOLUTION_H

#include <list>
#include <string>
#include <iostream>
#include "Point.h"
#include <deque>
#include <queue>
using namespace std;
/**
 * class that will hold the solution
 * of search
 */
class Solution {
private:


public:
    deque<Point*> sol;
    Solution();//constructor
    virtual ~Solution();//deconsructor
    Solution(deque<Point*> qlist);// constructor with sol queue
    deque<Point*> getSol();//get the sol member
    void print();
    void addNode(Point* node);//add node to the solution
    //friend ostream& operator << (ostream& os, const Solution &solution);
    //void print(queue<Node*> f);

};


#endif //ADVPRO1_SOLUTION_H