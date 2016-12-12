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
}

void Controller::getCommend() {
    string i;
    cin>>i>>endl;
    CreateGrid* size=new CreateGrid(i);
    int h=size->getInput().front();
    vector<int >::iterator it=size->getInput().begin();
    it++;
    MatrixLayout *mt=new MatrixLayout(size->getInput().front(),*it);
    center->setLayout(mt);
}