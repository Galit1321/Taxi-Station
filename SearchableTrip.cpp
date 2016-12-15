
#include "SearchableTrip.h"

/**
 *
 * @param layout1 the layout we working on
 * @param start -string of the start
 * @param end - string of the end
 * @return
 */
SearchableTrip::SearchableTrip(ILayout *layout1, int start_i, int start_j, int end_i, int end_j) {
    this->layout = layout1;
    this->init = this->layout->getNode(start_i, start_j);
    this->goal = this->layout->getNode(end_i, end_j);
    this->rideId=0;
    this->total_dis=0;
    this->traiff=0;
    this->numOfPass=0;

}

SearchableTrip::SearchableTrip(ILayout* layout1,Point* start,Point* end){
    this->layout = layout1;
    this->init = start;
    this->goal = end;
    this->rideId=0;
    this->total_dis=0;
    this->traiff=0;
    this->numOfPass=0;
}
SearchableTrip::SearchableTrip(ILayout* layout1,int start_i,int start_j,int end_i,int end_j, int rid, double tff){
    this->layout = layout1;
    this->init = this->layout->getNode(start_i, start_j);
    this->goal = this->layout->getNode(end_i, end_j);
    this->rideId=0;
    this->total_dis=0;
    this->traiff=0;
    this->numOfPass=0;
    this->traiff=tff;
    this->rideId=rid;
}
SearchableTrip::SearchableTrip() {

}
/**
 * to given node we want to know where we can move
 * @param s the given node
 * @return queue of all the node we can reach
 */
queue<Point *> SearchableTrip::getAllPossibleStates(Point *s) {
    std::queue<Point *> queue1;
    Point *n;
    if (layout->canGo(s, 'd')) {

        n = this->layout->getNode(s->getI() - 1, s->getJ());

        queue1.push(n);
    }
    if (layout->canGo(s, 'r')) {

        n = this->layout->getNode(s->getI(), s->getJ() + 1);

        queue1.push(n);
    }
    if (layout->canGo(s, 'u')) {

        n = this->layout->getNode(s->getI() + 1, s->getJ());

        queue1.push(n);
    }
    if (layout->canGo(s, 'l'))//go left
    {
        n = this->layout->getNode(s->getI(), s->getJ() - 1);
        queue1.push(n);
    }

    return queue1;

}

/**
 * getter og goal
 * @return this.goal
 */
Point *SearchableTrip::getGoalState() {
    return this->goal;
}

/**
 * getter of init
 * @return this->init
 */
Point *SearchableTrip::getInitialState() {
    return this->init;
}

//return the num of the passengers
int SearchableTrip::getNumOfPass() const {
    return numOfPass;
}

//add new passenger
void SearchableTrip::addPass() {
   numOfPass += 1;
}

//return ride id
int SearchableTrip::getRideId() const {
    return rideId;
}

//return the total distance
int SearchableTrip::getTotal_dis() const {
    return total_dis;
}

//set the total distance
void SearchableTrip::setTotal_dis(int total_dis) {
   total_dis += total_dis;
}

//return the tariff
int SearchableTrip::getTraiff() const {
    return traiff;
}

//set the tariff
void SearchableTrip::setTraiff(int traiff) {
    traiff = traiff;
}
