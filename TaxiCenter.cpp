
#include "TaxiCenter.h"
#include "Driver.h"
#include "Luxury.h"

/**
 * deconstructor
 * @return
 */
TaxiCenter::~TaxiCenter() {

    for (map<int, Passenger *>::iterator it = getAll_passngers().begin(); it != getAll_passngers().end(); ++it) {
        delete it->second;
    }
    for (map<int, SearchableTrip*>::iterator it = getTrip().begin(); it != getTrip().end(); ++it) {
        delete it->second;
    }trip.clear();
    all_passngers.clear();
    for (map<int, Car *>::iterator it = getCars().begin(); it != getCars().end(); ++it) {
        delete it->second;
    }
    cars.clear();
    //delete all driver
    for (map<int, Driver *>::iterator it = getDrivers().begin(); it != getDrivers().end(); ++it) {
        delete it->second;
    }
    drivers.clear();
    delete layout;
}

/**
 * default constructor
 * @return
 */
TaxiCenter::TaxiCenter() {
    drivers = map<int, Driver *>();
    free_drivers = vector<int>();
    all_passngers = map<int, Passenger *>();
    layout = NULL;
   // taken_drivers = vector<int>();
    cars = map<int, Car *>();

}

/**
 *  constructor
 * @return
 */
TaxiCenter::TaxiCenter(MatrixLayout *layout) : layout(layout) {

}


//create a vector of free drivers
vector<int> &TaxiCenter::getFree_drivers() {
    return free_drivers;
}

//return all the passengers
map<int, Passenger *> &TaxiCenter::getAll_passngers() {
    return all_passngers;
}

//add a car
Car* TaxiCenter::addCar(int id, string manufacturer, string color, int kind) {

    if (kind == 2) {
        return new Luxury(id, manufacturer, color);

    } else  {
        return new TaxiCab(id, manufacturer, color);
    }

}

//return the layout
MatrixLayout *TaxiCenter::getLayout() {
    return this->layout;
}

//set the layout
void TaxiCenter::setLayout(int h, int w) {
    this->layout = new MatrixLayout(h, w);
}

//set the layout
void TaxiCenter::setLayout(int h, int w, vector<int> *obs) {
    this->layout = new MatrixLayout(h, w, obs);
}

//return cabs
map<int, Car *> &TaxiCenter::getCars() {
    return cars;
}

//add driver
void TaxiCenter::addDriver(Driver *driver) {
   getDrivers().insert(std::pair<int, Driver *>(driver->getId(), driver));
  //  driver->setCar(getCars()[driver->getId()]);
}

/**
 * getter of map nme Drivers
 * @return
 */
map<int, Driver *> &TaxiCenter::getDrivers() {
    return drivers;
}

//conect taxi to driver
void TaxiCenter::setTaxiToDriver(int driver_id, int taxi_id) {
    Car *car = getCars()[taxi_id];
    Driver *driver = getDrivers()[driver_id];
    if ((driver == NULL) || (car == NULL)) {
        return;
    }
    driver->setCar(car);
    getCars().erase(getCars().begin());
}

//print location
void TaxiCenter::printLocation(int id) {
    Driver *d =drivers[id];
    if (d == NULL) {
        std::cout << "**driver not found" << endl;
    } else {
        cout.flush();
        int k=d->getCar()->getKind();
        std::cout << *(d->getCurr_pos());
        d->getCar()->setKind(k);
    }
}

//make one move
void TaxiCenter::move(int id) {
    Driver *driver = getDrivers()[id];
    if (driver == NULL) {
        std::cout << "driver not found";
    } else {
        driver->move();
    }
}

//return location
Point *TaxiCenter::getLocation(int id) {
    return getDriver(id)->getCurr_pos();
}

//add a new trip
SearchableTrip* TaxiCenter::addTrip(MatrixLayout *l, int i, int j, int end_x, int end_y, int id, int tariff,
                                    int numOfPass) {
    SearchableTrip* trip=new SearchableTrip(l, i,
                       j, end_x, end_y,id, tariff, numOfPass);

    return trip;
}

//do the bfs algoritm
void TaxiCenter::doBfs(int id) {
    getTrip()[id]->setSolution();
}

//find the closer driver
Driver *TaxiCenter::findCloser(Point *p) {
    if(getFree_drivers().empty()){
        return NULL;
    }
    for (std::vector<int>::iterator it = free_drivers.begin(); it != free_drivers.end(); it++){
        if( (getDriver(getFree_drivers()[*it])->getCurr_pos()->operator==(*p) )){
            return getDriver(getFree_drivers()[*it]);
        }
    } return NULL;

}

//return a driver
Driver *TaxiCenter::getDriver(int id) {
    return getDrivers()[id];;
}

//return taxi
Car *TaxiCenter::getTaxi(int id) {
    return getCars()[id];
}

/**
 * set the layout of taxicenter
 * @param layout
 */
void TaxiCenter::setLayout(MatrixLayout *layout) {
    this->layout = layout;
}

/**
 * finish all trip of drivers that we have in the taxicenter
 */
void TaxiCenter::finishAllTrip() {
    for (map<int, Driver *>::iterator it = getDrivers().begin(); it != getDrivers().end(); ++it) {
        it->second->finishTrip();
        free_drivers.push_back(it->second->getId());
    }

}
//return map of trips
 map<int, SearchableTrip *> &TaxiCenter::getTrip()  {
    return trip;
}

//set a trip
void TaxiCenter::setTrip(const map<int, SearchableTrip *> &trip) {
    TaxiCenter::trip = trip;
}


