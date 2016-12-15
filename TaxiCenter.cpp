
#include "TaxiCenter.h"



/**
 * deconstructor
 * @return
 */
TaxiCenter::~TaxiCenter() {
    for(map<int,Car*>::iterator it = getCars().begin(); it != getCars().end(); ++it) {
        delete  it->second;
    }cars.clear();
    ///delete all driver
    for(map<int,Driver*>::iterator it = getDrivers().begin(); it != getDrivers().end(); ++it) {
        delete  it->second;
    }
    drivers.clear();
    for(map<int,Passenger*>::iterator it = getAll_passngers().begin(); it != getAll_passngers().end(); ++it) {
        delete  it->second;
    }all_passngers.clear();
delete layout;
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
    cars = map<int, Car*>();

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

void TaxiCenter::addCar(Car *c) {
getCars().insert(std::pair<int,Car*>(c->getId(),c));
}

MatrixLayout* TaxiCenter::getLayout() {
    return this->layout;
}

//return cabs
map<int , Car*> &TaxiCenter::getCars() {
    return cars;
}

//add driver
void TaxiCenter::addDriver(Driver *driver) {
    free_drivers.push_back(driver->getId());
    drivers.insert( std::pair<int,Driver*>(driver->getId(),driver));
}

map<int, Driver *> &TaxiCenter::getDrivers() {
    return drivers;
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
void  TaxiCenter::printLocation(int id) {
    Driver* d=getDrivers()[id];
    if (d==NULL){
        std::cout<<"driver not found"<<endl;
    }else{
       std::cout<<*d->getCurr_pos();
    }
}

//make one move
void TaxiCenter::move(int id) {
    Driver* driver=getDrivers()[id];
    if (driver==NULL){
        std::cout<<"driver not found";
    }else {
        driver->getCar()->move();
    }
}

//return location
Point* TaxiCenter::getLocation(int id) {
    return getDriver(id)->getCurr_pos();
}

//find closer driver
Driver* TaxiCenter::findCloser(Point* orign) {
Solution* solution_end;
    Solution* solution_tmp;
    vector<int >::iterator iterator1=getFree_drivers().begin();
    Driver* driver=getDriver(*iterator1);
    iterator1++;
    Driver* driver1;
    solution_end=driver->doBFS(orign);
while(iterator1!=getFree_drivers().end()){
    if (solution_end->getSol().size()==1){//meaning the driver is in the sqr of the trip already
        return driver;
    }
    driver1=getDriver(*iterator1);
    solution_tmp=driver1->doBFS(orign);
    if (solution_tmp->sol.size()<solution_end->sol.size()){
        driver=driver1;
    }iterator1++;
}
    return driver;
}

//return a driver
Driver* TaxiCenter::getDriver(int id){
    return getDrivers()[id];;
}

//return taxi
Car* TaxiCenter::getTaxi(int id) {
    return getCars()[id];
}

void TaxiCenter::setLayout(MatrixLayout *layout) {
    TaxiCenter::layout = layout;
}
/**
 * finish all trip of drivers that we have in the taxicenter
 */
void TaxiCenter::finishAllTrip() {
    for(map<int,Driver*>::iterator it = getDrivers().begin(); it != getDrivers().end(); ++it) {
        it->second->finishTrip();
    }

}