//
// Created by galit on 23/11/16.
//

#ifndef ADVPRO1_ABSCREATABLE_H
#define ADVPRO1_ABSCREATABLE_H


#include "string"
#include "list"
/**
 * a class that phase the string input
 * to list of token we need to create object from
 */
using namespace std;
class Create{
protected:
    list<string> tokens;
    bool work;
public:
    virtual ~Create();//deconstructor
    Create();//constructor
    list<string> getTokens() const;//getter to tokens
    Create(string &input);

    bool isWork() const;

//constructor with the input to divide

};
#endif //ADVPRO1_ABSCREATABLE_H