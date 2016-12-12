
#include "TaxiCenter.h"

 map<long, Driver *> &TaxiCenter::getDrivers() {
    return drivers;
}

/**
 * deconstructor
 * @return
 */
TaxiCenter::~TaxiCenter() {

}

/**
 * default constructor
 * @return
 */
TaxiCenter::TaxiCenter() {
    drivers = map<long, Driver *>();
    locations = map<Point, Driver *>();
    free_drivers = vector<long>();
    all_passngers = map<long, Passenger *>();
    layout = NULL;
    cars = map<long, TaxiCab*>();
}

/**
 *  constructor
 * @return
 */
TaxiCenter::TaxiCenter(MatrixLayout *layout) : layout(layout) {

}

//return location
 map<Point, Driver *> &TaxiCenter::getLocations()  {
    return locations;
}

//create a vector of free drivers
 vector<long> &TaxiCenter::getFree_drivers() {
    return free_drivers;
}

//return all the passengers
map<long, Passenger *> &TaxiCenter::getAll_passngers() {
    return all_passngers;
}

ILayout* TaxiCenter::getLayout() {
    return NULL;
}

//return cabs
map<long, TaxiCab*> &TaxiCenter::getCars() {
    return cars;
}

//return commend from the user
void TaxiCenter::getCommend(int num_commend, string s) {

}

//add driver
void TaxiCenter::addDriver(Driver *driver) {

}

//create taxi
void TaxiCenter::createTaxi(string parms) {

}

//conect taxi to driver
void TaxiCenter::setTaxiToDriver(long driver_id, long taxi_id) {

}

//print location
string TaxiCenter::printLocation(long id) {
    return "";
}

//make one move
void TaxiCenter::move(long id) {

}

//return location
Point* TaxiCenter::getLocation(long id) {
    return NULL;
}

//create a trip
SearchableTrip* createTrip(long id) {
    return NULL;
}

//find closer driver
Driver* TaxiCenter::findCloser(Point *orign) {
    return NULL;
}

//return a driver
Driver* TaxiCenter::getDriver(long id){
    return NULL;
}

//return taxi
TaxiCab* TaxiCenter::getTaxi(long id) {
    return NULL;
}

void TaxiCenter::setLayout(ILayout *layout) {
    TaxiCenter::layout = layout;
}
