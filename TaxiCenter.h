

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
    map<Point,Driver*> locations;
    vector<int > free_drivers;
    map<int,Passenger*> all_passngers;
    ILayout* layout;
    map<int ,TaxiCab*> cars;
public:
    TaxiCenter(MatrixLayout* layout);//constructor
    TaxiCenter();//defult constructor
    //return commend from the user
    void getCommend(int num_commend,string s);
    /***********************************/
    void addCar(Car* c);
    /**********************************************************************/
    void setLayout(ILayout *layout);

    //add driver
    void addDriver(Driver* driver);
    //create taxi
    void createTaxi(string parms);
    //conect taxi to driver
    void setTaxiToDriver(int driver_id, int taxi_id);
    //print location
    string printLocation(int id);
    //make one move
    void move(int id);
    //return a driver
    Driver* getDriver(int id);
    //return taxi
    TaxiCab* getTaxi(int id);
    //return location
    Point* getLocation(int id);
    //create a trip
    SearchableTrip* createTrip(int id);
    //find closer driver
    Driver* findCloser(Point* orign);
    //return the drivers
     map<int , Driver*> &getDrivers() ;
    //return location
    map<Point, Driver*> &getLocations() ;
    //create a vector of free drivers
     vector<int > &getFree_drivers() ;
    //return all the passengers
     map<int , Passenger*> &getAll_passngers() ;
    ILayout* getLayout() ;
    //return cabs
    map<int, TaxiCab*> &getCars() ;
    virtual ~TaxiCenter();//deconstructor

};


#endif //TAXI02_TAXICENTER_H
