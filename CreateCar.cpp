//
// Created by galit on 12/12/16.
//

#include "CreateCar.h"
/*
 * constructor
 */
CreateCar::CreateCar(string &input) : Create(input) {
    if (this->tokens.size()!=4){
       work=false;
    }
    list<string>::iterator iterator1=this->tokens.begin();
    id=std::stoi(*iterator1);
    iterator1++;
    kind=std::stoi(*iterator1);
    iterator1++;
    manufactor=*iterator1;
    iterator1++;
    color =*(iterator1);
    iterator1++;
    work=true;



}
/**
 * getter of id
 * @return
 */
int CreateCar::getId() const {
    return id;
}
/**
 * getter of kind of car
 * @return
 */
int CreateCar::getKind() const {
    return kind;
}
/**
 * getter of color
 * @return
 */
const string &CreateCar::getColor() const {
    return color;
}
/*-*
 * getter of manufactor
 */
const string &CreateCar::getManufactor() const {
    return manufactor;
}






