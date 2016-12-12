//
// Created by galit on 12/12/16.
//

#include "CreateCar.h"

CreateCar::CreateCar(string &input) : Create(input) {

}
Car* CreateCar::getCar() {
    int id;
    int kind;
    string color;
    string manufactor;

    if (this->tokens.size()!=4){
        return NULL;
    }
    list<string>::iterator iterator1=this->tokens.begin();
    id=atoi(*iterator1);
    iterator1++;
    kind=atoi(*iterator1);
    iterator1++;

    manufactor=*iterator1;
    iterator1++;
    color =*(iterator1);
    iterator1++;
    if (kind==1){
        return new TaxiCab(id,manufactor,color);
    }else if (kind==2) {
        return  new Luxury();///need to work on tommarow
    }
    return NULL;
}