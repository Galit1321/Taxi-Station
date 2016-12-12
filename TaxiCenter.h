

#ifndef TAXI02_TAXICENTER_H
#define TAXI02_TAXICENTER_H

#include "map"
#include "TaxiCab.h"
#include "Driver.h"
#include "ILayout.h"
#include "Passenger.h"
#include "SearchableTrip.h"
class TaxiCenter {
protected:
map<long,Driver*> drivers;
    map<Point,Driver*> locations;
    vector<long> free_drivers;
    map<long,Passenger*> all_passngers;
    ILayout* layout;
    map<long ,TaxiCab*> cars;
public:
    TaxiCenter(ILayout *layout);//constructor
    TaxiCenter();//defult constructor
    //return commend from the user
    void getCommend(int num_commend,string s);
    //add driver
    void addDriver(Driver* driver);
    //create taxi
    void createTaxi(string parms);
    //conect taxi to driver
    void setTaxiToDriver(long driver_id,long taxi_id);
    //print location
    string printLocation(long id);
    //make one move
    void move(long id);
    //return a driver
    Driver* getDriver(long id);
    //return taxi
    TaxiCab* getTaxi(long id);
    //return location
    Point* getLocation(long id);
    //create a trip
    SearchableTrip* createTrip(long id);
    //find closer driver
    Driver* findCloser(Point* orign);
    //return the drivers
     map<long, Driver*> &getDrivers() ;
    //return location
    map<Point, Driver*> &getLocations() ;
    //create a vector of free drivers
     vector<long> &getFree_drivers() ;
    //return all the passengers
     map<long, Passenger*> &getAll_passngers() ;
    ILayout* getLayout() ;
    //return cabs
    map<long, TaxiCab*> &getCars() ;
    virtual ~TaxiCenter();//deconstructor

};


#endif //TAXI02_TAXICENTER_H
