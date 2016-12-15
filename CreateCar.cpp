//
// Created by galit on 12/12/16.
//

#include "CreateCar.h"
/**
 * class CreateCar
 * a class that create a car
 */
CreateCar::CreateCar(string &input) : Create(input) {

}
Car* CreateCar::getCar() {
    int id;
    int kind;
    string color;
    string manufactor;
    //set all the car parameter according to the input
    if (this->tokens.size()!=4){
        return NULL;
    }
    list<string>::iterator iterator1=this->tokens.begin();
    iterator1++;
    kind=std::stoi(*iterator1);
    iterator1++;
    manufactor=*iterator1;
    iterator1++;
    color =*(iterator1);
    iterator1++;


    //create a car according to her kind
    if (kind==1){
        return new TaxiCab(id,manufactor,color);
    }else if (kind==2) {
        return  new Luxury(id,manufactor,color);///need to work on tommarow
    }
    return NULL;
}

