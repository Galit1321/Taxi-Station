

#include "Solution.h"

/**
 * constructor
 * @return
 */
Solution::Solution()
{
    deque<Point*> g;
    this->sol = g;
}
/**
 * desonfructor
 */
Solution::~Solution() {

}
/**
 * constructor
 * @param qlist
 * @return
 */
Solution::Solution(std::deque<Point*> qlist)
{
    this->sol = qlist;
}


/**
 * getter to solition
 * @return
 */
deque<Point*> Solution::getSol()
{
    return this->sol;
}
/**
 * add node to sol queue
 * @param node what we want to add
 */
void Solution::addNode(Point* node)
{
    this->sol.push_front(node);
}
/** `
 * print the solutiom
 * @param os
 * @param solution this object
 * @return
 */
void Solution::print() {
    while (!sol.empty()){
        std::cout<<sol.front();
        sol.pop_front();
    }   }

