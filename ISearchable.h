//****************
// interface of obJect
// we can preform search on it
//between to nodes

#ifndef ADVPRO1_ISEARCHABLE_H
#define ADVPRO1_ISEARCHABLE_H
#include <queue>
#include "Point.h"
#include "list"
using namespace std;
/*********
 * Interface to searchable objects
 * like a trip so that in any
 * given point we can know where we can go
 *
 */
class ISearchable {
public:
    virtual Point* getInitialState()=0;//get the state of the begining from
    virtual Point* getGoalState()=0;//where we want to get
    virtual queue<Point*> getAllPossibleStates(Point *s)=0;// receive where we can go from it

};


#endif //ADVPRO1_ISEARCHABLE_H