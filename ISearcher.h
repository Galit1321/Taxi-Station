//
//Interface to all
// forms of search we want .
//

#ifndef ADVPRO1_ISEARCHER_H
#define ADVPRO1_ISEARCHER_H

#include "Solution.h"
#include "ISearchable.h"

/**
 * interface to search
 * methods like BFS and any kind
 * of class that will conduct search
 */
class ISearcher
{

protected:
    //the method that will do the search by what ISearchable given
    virtual Solution* search(ISearchable* searchable)=0;
};

#endif //ADVPRO1_ISEARCHER_H