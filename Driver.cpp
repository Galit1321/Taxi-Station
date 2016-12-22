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
    age =0;
    experience =0;
    stat = " ";
    car = NULL;
   trip=NULL;
    satisfaction=0.0;

}

/**
 * copy constructor
 * @param obj
 * @return copy of the given object
 */
Driver ::Driver(Driver &object) {
    this->id = object.getId();
    this->experience = object.getExperience();
    this->age = object.getAge();
    this->stat = object.getStat();
    this->curr_pos = object.getCurr_pos();
    trip=object.getTrip();
}
//constructor
Driver ::Driver(int id ,int age ,string stat , int experience) {
    this->id = id;
    this->age = age;
    this->stat = stat;
    this->experience =experience;
    car = NULL;
    solution=  deque<Point*>();
    trip=NULL;
}

Driver::~Driver() {

    if (trip!=NULL)
    delete trip;
}


//compare between 2 drivers
bool Driver ::operator==(const Driver &driver1) const {
    return ((id == driver1.getId())&&(stat == driver1.getStat())
    &&(age == driver1.getAge())&&(experience == driver1.getExperience()));

}

//run the bfs algoritm
deque<Point*> Driver ::doBFS(SearchableTrip* psEnd) {
   BFS* bfs=new BFS();
   SearchableTrip* trip1=new SearchableTrip(psEnd->getLayout(),curr_pos,psEnd->getInitialState());
    deque<Point*> sol=bfs->search(trip1);
    delete trip1;
    delete bfs;
   return sol;
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
/**
 * finish the driver trip
 */
void Driver::finishTrip() {
    int cont=this->solution.size();
    for (int i=0;i<cont;i++){
        move();
    }

}

/**
 *
 * @param layout1
 * @param start_i
 * @param start_j
 * @param end_i
 * @param end_j
 * @param rid
 * @param tff
 * @param nop
 */

void Driver::setTrip(ILayout* layout1,int start_i,int start_j,int end_i,int end_j, int rid, double tff,int nop) {
    if (this->trip!=NULL){
        delete trip;
    }
    this->trip=new SearchableTrip(layout1,start_i,start_j,end_i,end_j,rid,tff);
    trip->setNumOfPass(nop);
    BFS* bfs=new BFS();
    this->solution=bfs->search(trip);
    this->numOfUser+=trip->getNumOfPass();
    curr_pos=trip->getInitialState();
    delete bfs;

}
/**
 * driver move a qeure accoding to kind of car
 */
void Driver::move() {

    if (!solution.empty()){
        if (car->getKind()==1){
            curr_pos=solution.front();
            this->car->setMileage(this->car->getMileage()+1);
            solution.pop_front();
        }
       else{
            curr_pos=solution.front();
            solution.pop_front();
            this->car->setMileage(this->car->getMileage()+1);
            if (!solution.empty()){
                curr_pos=solution.front();
                solution.pop_front();
                this->car->setMileage(this->car->getMileage()+1);
            }

        }
    }
}
/**
 * add the satisfaction to total of that we have
 * @param satisfaction
 */
void Driver::setSatisfaction(float satisfaction) {
    this->satisfaction=(this->satisfaction*(numOfUser-trip->getNumOfPass())+satisfaction)/(float)this->numOfUser;
}\
/**
 * get setsatfaction
 * @return
 */
float Driver::getSatisfaction() {
    return  this->satisfaction;
}






