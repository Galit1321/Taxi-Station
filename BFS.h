//***************
// a class of bfs with search
//method that get searchable object to search on
//

#ifndef ADVPRO1_BFS_H
#define ADVPRO1_BFS_H

using namespace std;
#include <algorithm>
#include "Point.h"
#include "queue"
#include "list"
#include "ISearcher.h"
#include "vector"
class BFS : public ISearcher {

public:
    BFS();//constructor
    virtual ~BFS();//deconstructor
    Solution* search(ISearchable* searchable);// the search algoritm



};


#endif //ADVPRO1_BFS_H