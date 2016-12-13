//
// Created by galit on 12/12/16.
//

#include "Controller.h"
#include "CreateGrid.h"
#include "CreateDriver.h"
#include "CreateCar.h"
#include "CreateRide.h"
Controller::~Controller() {
 delete center;
}

Controller::Controller()  {

    center=new TaxiCenter();
    int h ;
    int w;
    cin>>h;
    cin>>w;
    int numOfObs;
    cin>>numOfObs;
    string obsVector;
    MatrixLayout *mt;
    if (numOfObs){
        cin>>obsVector;
        CreateGrid* size=new CreateGrid(obsVector);
        mt=new MatrixLayout(h,w,size->getInput());
        delete size;
    } else{
        mt=new MatrixLayout(h,w);
    }

    center->setLayout(mt);
}

void Controller::getCommend() {
   int commend;
    cin>>commend;
    bool success;
    while ((commend!=7)&&(success)){
        switch (commend){
            case 1:
                success=CommendOne();
                break;
            case 2:
                success=CommendTwo();
                break;
            case 3:
                success=CommendThree();
                break;
            case 4:
                success=CommendFour();
                break;
            case 6:
                success=CommendSix();
                break;

       }
        cin>>commend;

        }
    exit();

}
/**
 * commend one meaning create a driver
 * will call the class that phase the input and create driver
 * @return true is creation succes false if we got exception
 */
bool Controller::CommendOne(){
    string parm;
    cin>>parm;
  try{
      CreateDriver* cd=new  CreateDriver(parm);
    center->addDriver(cd->getDriver());
    center->setTaxiToDriver(cd->getDriver()->getId(),cd->getVehicle_id());
}catch(std::exception exception1) {
      return false;
  }
    return true;
}
bool Controller::CommendTwo(){
    string parm;
    cin>>parm;
    try{
        CreateRide* cd=new  CreateRide(parm);
       ILayout* m=center->getLayout();
        SearchableTrip* searchableTrip=new SearchableTrip(m,cd->start_x,cd->star_y,cd->end_x,cd->end_y,cd->id,cd->tariff);
        Driver* d=center->findCloser(searchableTrip->getInitialState());
        
    }catch(std::exception exception1) {
        return false;
    }
    return true;
}
/**
 * commend 3 to create a new car with agrument
 * given by cin
 * @return true if we success
 */
bool Controller::CommendThree(){
    string parm;
 cin>>parm;
    try{CreateCar* cc=new CreateCar(parm);
        center->addCar(cc->getCar());}
    catch (std::exception e){
        return false;
    }
    return true;

}
/**
 * commend 4 is to get the current position of driver with
 * id given in cin>>id and print it to screen
 * @return true if we found the driver and printed ,ohterwise false
 */
bool Controller::CommendFour(){
    int id;
    cin>>id;
    Point* p=center->getLocation(id);
    if (p==NULL){
        return false;
    }
std::cout<<*p;

    return true;
}

bool  Controller::CommendSix(){

}

void Controller::exit() {

}