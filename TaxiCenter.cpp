
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
    locations = map<Point, Driver *>();
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

//return location
 map<Point, Driver *> &TaxiCenter::getLocations()  {
    return locations;
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
    return NULL;
}

//return cabs
map<int , TaxiCab*> &TaxiCenter::getCars() {
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
void TaxiCenter::setTaxiToDriver(int driver_id, int taxi_id) {

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
