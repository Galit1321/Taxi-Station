//
// Created by galit on 14/11/16.
//

#ifndef ADVPRO1_ABSLAYOUT_H
#define ADVPRO1_ABSLAYOUT_H

#include "Point.h"
#include "string"
using namespace std;

/**********************
 * Interface that
 * represent the layouts given
 * to us (any layout we want to fit
 * out porpose will implament it
 *************************************/

class ILayout {
public:
    virtual bool canGo(Point* n, char d)=0;//method to see on the

    //get point in index
    virtual Point* getNode(int i,int j)=0;
};


#endif //ADVPRO1_ABSLAYOUT_H