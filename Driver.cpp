//
// Created by michal on 12/1/16.
//

#include "Driver.h"

/**
 * default constructor
 * @return
 */
Driver ::Driver() :Person(){
id=0;
    
}

/**
 * copy constructor
 * @param obj
 * @return copy of the given object
 */
Driver ::Driver(Driver &object) {
    this->id = object.getId();


}
//constructor
Driver ::Driver(int id ,int age ,string stat , int experience) {
    this->id = id;
    this->age = age;
    this->stat = stat;
    this->experience =experience;
    this->curr_pos=new Point(0,0);
}

Driver::~Driver() {
delete curr_pos;
}


//compare between 2 drivers
bool Driver ::operator==(const Driver &driver1) const {
    return ((id == driver1.getId())&&(stat == driver1.getStat())
    &&(age == driver1.getAge())&&(experience == driver1.getExperience()));

}

//run the bfs algoritm
Solution* Driver ::doBFS(SearchableTrip* psEnd) {
   BFS* bfs=new BFS();
    SearchableTrip* trip1=new SearchableTrip(psEnd->getLayout(),curr_pos,psEnd->getInitialState());
    return bfs->search(trip1);
}

//return the driver id
int Driver::getId() const {
    return id;
}

//return the driver age
int Driver::getAge() const {
    return age;
}

//return the years of experience of the driver
int Driver::getExperience() const {
    return experience;
}

//return the num of the users
int Driver::getNumOfUser() const {
    return numOfUser;
}

//set the driver id
void Driver::setId(int id) {
    Driver::id = id;
}

//set the driver age
void Driver::setAge(int age) {
    Driver::age = age;
}

//set the years of experience of the driver
void Driver::setExperience(int experience) {
    Driver::experience = experience;
}

//set the num of the users
void Driver::setNumOfUser(int numOfUser) {
    Driver::numOfUser = numOfUser;
}

//set the status of the driver
void Driver::setStat(string stat) {
    Driver::stat = stat;
}

//set the car of the driver
void Driver::setCar(Car *car) {
    Driver::car = car;
}

//return the status of the driver
string Driver::getStat() const {
    return stat;
}

////return the car of the driver
Car *Driver::getCar() const {
    return car;
}


SearchableTrip *Driver::getTrip() const {
    return trip;
}

void Driver::finishTrip() {
    int cont=this->solution->sol.size();
    for (int i=0;i<cont;i++){
        move();
    }

}



void Driver::setTrip(SearchableTrip *trip) {
    BFS* bfs=new BFS();
    this->solution=bfs->search(trip);
    this->numOfUser+=trip->getNumOfPass();
    curr_pos=trip->getInitialState();
    delete bfs;

}
void Driver::move() {
    solution->sol.pop_front();
    if (!solution->sol.empty()){
        curr_pos=solution->getSol().front();
    }
}
void Driver::setSatisfaction(float satisfaction) {
    this->satisfaction=(this->satisfaction*(numOfUser-trip->getNumOfPass())+satisfaction)/(float)this->numOfUser;
}
float Driver::getSatisfaction() {
    return  this->satisfaction;
}






