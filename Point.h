//
//
//

#ifndef ADVPRO1_NODE_H
#define ADVPRO1_NODE_H
using namespace std;

#include <iostream>
#include <boost/serialization/access.hpp>

/************
 * a class to rep
 * the point on the grid
 *
 */
class Point{
protected:

public:
    int i;//x axis
    int j;//y axis
    Point* parent;//where he came in the trip
    int  cost;//cost of node
    Point(int row,int col);//constructor
    Point();//default conn
    virtual ~Point();//desonstructor
    Point(const Point &obj);//copy constructor
    //getter of i
    int getI() const;
    //getter of j
    int getJ() const;
    //return the tariff
    int getCost() const;
    // set the tariff
    void setCost(int cost);
    bool operator<(const Point &node1) const ;
    bool operator>(const Point &node1) const ;
    //compare 2 points
    bool operator==(const Point &node1) const ;
   // bool operator==(const Point &)
    Point *getParent() const;
    //setter to parents
    void setParent(Point *parent);
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & i;
        ar & j;
        ar & this->cost;
    }
    friend ostream &operator<<( ostream &output,
                                const Point &p) {
        output << "(" << p.getI() << "," << p.getJ()<<")"<<endl;
        return output;
    }
};


#endif //ADVPRO1_NODE_H