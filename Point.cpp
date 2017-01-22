//
// Created by galit on 14/11/16.
//

#include <limits>
#include <climits>
#include "Point.h"
Point::Point(int row, int col) {
    i=row;
    j=col;
    this->cost=INT_MAX;
    this->parent= NULL;
}
Point::Point() {
    this->cost=INT_MAX;
    this->parent= NULL;
}
Point::~Point() {
//the class that hold the point object will delet it
    //alone with the parent if necessary
}


/**
 * copy constructor
 * @param obj
 * @return copy of the given object
 */
Point::Point(const Point &obj) {
    this->i=obj.getI();
    this->j=obj.getJ();
    this->parent=obj.getParent();
    this->cost=obj.getCost();
}
/**
 * operator overloading to == that will
 * check to see if point are equel
 * @param node the point want to comper with this
 * @return true if node eq to this
 */
bool Point ::operator==(const Point &node)const {

    return (i==node.getI())&&(j==node.getJ());
}
/**
 * getter of j
 * @return
 */
int Point ::getJ() const {
    return j;
}
bool Point::operator>(const Point &node1) const {
    return (i<node1.getI())||(j<node1.getJ());
}
/**
 * getter of the point parent
 * null if we didnt set one
 * @return
 */
Point  *Point::getParent() const {
    return parent;
}
/**
 * setter to parent
 * @param parent
 */
void Point::setParent(Point  *parent) {
    this->parent = parent;
}
/**
 * getter of i
 * @return
 */
int Point::getI() const {
    return i;
}


/**
 * getter of cost
 * @return the cost of point obhect
 */
int Point::getCost() const {
    return cost;
}
/**
 * setter to cost
 * @param cost
 */
void Point::setCost(int cost) {
    Point::cost = cost;
}

/**
 * operator overloading to < that will
 * check to see if point are smmaler
 * @param node the point want to comper with this
 * @return true if node smaller to this
 */
bool Point::operator<(const Point &node1) const {
    return (node1.getJ()<j)||(node1.getI()<i);
}

std::string Point::print() {
    string s="(";
    s+=getI();
    s+=",";
    s+=getJ();
    s+=")";
}