//
// Created by galit on 12/12/16.
//

#include "Controller.h"
#include "CreateGrid.h"
#include "MatrixLayout.h"
Controller::~Controller() {
 delete center;
}

Controller::Controller()  {

    center=new TaxiCenter();
    int h ;
    int w;
    cin>>h>>w>>endl;
    int numOfObs;
    cin>>numOfObs>>endl;
    string obsVector;
    MatrixLayout *mt;
    if (numOfObs){
        cin>>obsVector>>end;
        CreateGrid* size=new CreateGrid(obsVector);
        mt=new MatrixLayout(h,w,size->getInput());
    } else{
        mt=new MatrixLayout(h,w);
    }
    center->setLayout(mt);
}

void Controller::getCommend() {
   int commend;
    cin>>commend>>end;
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
                success=CommendThre();
                break;
            case 4:
                cout<<CommendFour()<<end;
                break;
            case 6:
                success=CommendSix();
                break;

       }
        cin>>commend>>endl;

        }

}

bool Controller::CommendOne(){

}
bool Controller::CommendTwo(){

}
bool Controller::CommendThre(){

}
string Controller::CommendFour(){

}

bool  Controller::CommendSix(){

}