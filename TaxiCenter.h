

#ifndef TAXI02_TAXICENTER_H
#define TAXI02_TAXICENTER_H

#include "map"
#include "TaxiCab.h"
#include "Driver.h"
#include "ILayout.h"
#include "MatrixLayout.h"
#include "Passenger.h"
#include "SearchableTrip.h"
class TaxiCenter {
protected:
    map<int,Driver*> drivers;
    map<int,SearchableTrip*> trip;
public:
    //return map of trips
 map<int, SearchableTrip *> &getTrip() ;
    //set a trip
    void setTrip(const map<int, SearchableTrip *> &trip);



protected:
    vector<int > free_drivers;
    map<int,Passenger*> all_passngers;
    MatrixLayout* layout;
    map<int ,Car*> cars;
public:
    void doBfs(int id);
    SearchableTrip* addTrip(MatrixLayout *l, int i, int j, int end_x, int end_y, int id, int tariff,
                                         int numOfPass);
    TaxiCenter(MatrixLayout* layout);//constructor
    TaxiCenter();//defult constructor
    //add a car
    Car* addCar(int id ,string manufacturer,string color,int kind);
    //set the layout
    void setLayout(MatrixLayout *layout);
    //set the layout
    void setLayout(int h,int w);
    //set the layout
    void setLayout(int h,int w, vector<int>* obs);
    //add driver
    void addDriver(Driver *driver);
    //void addDriver(int id ,int age,string stat,int exp);
    //conect taxi to driver
    void setTaxiToDriver(int driver_id, int taxi_id);
    //print location
   void printLocation(int id);
    //make one move
    void move(int id);
    //return a driver
    Driver* getDriver(int id);
    //return taxi
    Car* getTaxi(int id);
    //return location
    Point* getLocation(int id);

    //find closer driver
    Driver *findCloser(Point *p);
    //return the drivers
     map<int , Driver*> &getDrivers() ;

    //create a vector of free drivers
     vector<int > &getFree_drivers() ;
    //return all the passengers
     map<int , Passenger*> &getAll_passngers() ;
    MatrixLayout* getLayout() ;
    //return cabs
    map<int, Car*> &getCars() ;
    virtual ~TaxiCenter();//deconstructor
    //finish the trip of drivers that we have in the taxicenter
    void finishAllTrip();

};


#endif //TAXI02_TAXICENTER_H
