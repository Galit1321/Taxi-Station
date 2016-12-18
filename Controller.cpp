//
// Created by galit on 12/12/16.
//

#include "Controller.h"
#include "CreateGrid.h"
#include "CreateDriver.h"
#include "CreateCar.h"
#include "CreateRide.h"
#include <cstring>
using namespace std;
/**
 * destructor
 */
Controller::~Controller() {
 delete center;
}
/**
 * constructor
 * @return
 */
Controller::Controller()  {

    center=new TaxiCenter();
    string sizeGride;
    getline(cin,sizeGride);
    char tmp[10];
    int h ;
    int w;
  //  cin>>h;
    int pos=sizeGride.find(" ");
    h = atoi(strcpy(tmp,sizeGride.substr(0,pos).c_str()));
    sizeGride.erase(0, pos+1);
    w = atoi(sizeGride.c_str());
    int numOfObs;
    cin>>numOfObs;
    string obsVector;
    vector<int> v;
   if  (numOfObs){
       while(numOfObs){
           cin>>obsVector;
           CreateGrid* size;
            size=new CreateGrid(obsVector);
v.insert(v.end(),size->getInput().begin(),size->getInput().end());
           delete size;
           numOfObs--;
       }
       center->setLayout(h,w,&v);

    } else{
        center->setLayout(h,w);
    }
}
/**
 * busy waiting function to get commend from user
 * destion to run on diff thred
 */
void Controller::getCommend() {
   int commend;
    cin>>commend;
    bool success= true;
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
    center->addDriver(cd->getId(),cd->getAge(),cd->getStat(),cd->getExp());
    center->setTaxiToDriver(cd->getId(),cd->getVehicle_id());
      delete cd;
}catch(std::exception exception1) {
      return false;
  }

    return true;
}
/**
 * commend two that create a new ride
 * @return true if action sucessful otherwise false
 */
bool Controller::CommendTwo(){
    string parm;
    cin>>parm;
    try{
        CreateRide* cd=new  CreateRide(parm);
        center->getDriver(center->findCloser())->setTrip(center->getLayout(),cd->start_x,cd->star_y,cd->end_x,cd->end_y,cd->id,cd->tariff,cd->numOfPass);
       delete cd;
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
        center->addCar(cc->getId(),cc->getManufactor(),cc->getColor(),cc->getKind());
    delete cc;
    }
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
    center->printLocation(id);
    return true;
}
/**
 * run all current driver that have a trip to finish point
 * @return
 */
bool  Controller::CommendSix(){
center->finishAllTrip();
    return true;
}

