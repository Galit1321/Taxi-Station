

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
    vector<int > free_drivers;
    map<int,Passenger*> all_passngers;
    ILayout* layout;
    map<int ,Car*> cars;
public:
    TaxiCenter(MatrixLayout* layout);//constructor
    TaxiCenter();//defult constructor
    void addCar(Car* c);
    void setLayout(ILayout *layout);
    //add driver
    void addDriver(Driver* driver);
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
    Driver* findCloser(Point* orign);
    //return the drivers
     map<int , Driver*> &getDrivers() ;

    //create a vector of free drivers
     vector<int > &getFree_drivers() ;
    //return all the passengers
     map<int , Passenger*> &getAll_passngers() ;
    ILayout* getLayout() ;
    //return cabs
    map<int, Car*> &getCars() ;
    virtual ~TaxiCenter();//deconstructor
    void finishAllTrip();

};


#endif //TAXI02_TAXICENTER_H
