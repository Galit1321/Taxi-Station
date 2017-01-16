//
//bfs search on searchable object
//


#include "BFS.h"


/**
 * default constructor
 * @return
 */
BFS::BFS() {


}

/**
 * we dont have any data members clear the queue if there are nodes left in it
 */
BFS::~BFS() {

}

/**
 * the search algorithm that
 * @param searchable object
 * of which we can conduct search on it
 * @return solution object
 * that will hold the solution of the searc
 */
deque<Point*> BFS::search(ISearchable *searchable) {
    deque<Point*> s;
    vector<Point*> open;
    vector<Point*> closed;//
    Point* n;
    n = searchable->getInitialState();
    open.push_back(n);
    vector<Point*>::iterator it1;
    vector<Point*>::iterator iterator1;
    Point* node=searchable->getGoalState();
    while (!open.empty()) {
        closed.push_back(n);

        if ((n!= NULL)&&(n ==node)){
            while (n!= NULL)//we didnt reach the root of tree
            {
                s.push_front(n);
                n = n->getParent();
            }
            break;
        }

        queue<Point*> l = searchable->getAllPossibleStates(n);
        while (!l.empty()) {
            it1=find(open.begin(),open.end(),l.front());
            iterator1=find(closed.begin(),closed.end(),l.front());
                if (iterator1 == closed.end()) {
                if (it1 == open.end()) {//l.front is not in open
                    l.front()->setParent(n);
                    l.front()->setCost(n->getCost() + 1);
                    open.push_back(l.front());
                } else if ((l.front()->getCost() < n->getCost() + 1)) {
                    l.front()->setCost(n->getCost() + 1);
                    l.front()->setParent(n);
                    open.push_back(l.front());
                }
            }
            l.pop();
        }
        n = open.front();
        open.erase(open.begin());
    }
    open.clear();
    return s;
}

