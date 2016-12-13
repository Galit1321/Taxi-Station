
#include "TaxiCenter.h"

 map<int, Driver *> &TaxiCenter::getDrivers() {
    return drivers;
}

/**
 * deconstructor
 * @return
 */
TaxiCenter::~TaxiCenter() {

}
void TaxiCenter::addCar(Car *c) {

}
/**
 * default constructor
 * @return
 */
TaxiCenter::TaxiCenter() {
    drivers = map<int, Driver *>();
    free_drivers = vector<int >();
    all_passngers = map<int , Passenger *>();
    layout = NULL;
    cars = map<int, TaxiCab*>();
}

/**
 *  constructor
 * @return
 */
TaxiCenter::TaxiCenter(MatrixLayout *layout) : layout(layout) {

}


//create a vector of free drivers
 vector<int > &TaxiCenter::getFree_drivers() {
    return free_drivers;
}

//return all the passengers
map<int , Passenger *> &TaxiCenter::getAll_passngers() {
    return all_passngers;
}

ILayout* TaxiCenter::getLayout() {
    return this->layout;
}

//return cabs
map<int , TaxiCab*> &TaxiCenter::getCars() {
    return cars;
}

//add driver
void TaxiCenter::addDriver(Driver *driver) {
    free_drivers.push_back(driver->getId());
    drivers.insert( std::pair<int,Driver*>(driver->getId(),driver));
}


//conect taxi to driver
void TaxiCenter::setTaxiToDriver(int driver_id, int taxi_id) {
    Car* car=getCars()[taxi_id];
   Driver* driver=getDrivers()[driver_id];

    if((driver==NULL)||(car==NULL)){
        return;
    }driver->setCar(car);
}

//print location
string TaxiCenter::printLocation(int id) {
    return "";
}

//make one move
void TaxiCenter::move(int id) {

}

//return location
Point* TaxiCenter::getLocation(int id) {
    return NULL;
}

//create a trip
SearchableTrip* createTrip(int id) {
    return NULL;
}

//find closer driver
Driver* TaxiCenter::findCloser(Point *orign) {
    return NULL;
}

//return a driver
Driver* TaxiCenter::getDriver(int id){
    return NULL;
}

//return taxi
TaxiCab* TaxiCenter::getTaxi(int id) {
    return NULL;
}

void TaxiCenter::setLayout(ILayout *layout) {
    TaxiCenter::layout = layout;
}
