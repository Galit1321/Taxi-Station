//
// Created by galit on 12/12/16.
//

#include <iostream>
#include "CreateCar.h"
/*
 * constructor
 */
CreateCar::CreateCar(string &input) : Create(input) {
    if (this->tokens.size()!=4){
        work = false ;
        cin.clear();
        cin.ignore();
        return ;
    }
    list<string>::iterator iterator1=this->tokens.begin();
    if (((*iterator1).find_first_not_of("0123456789") != std::string::npos)){
        work = false;
    }
    id=std::stoi(*iterator1);
    iterator1++;
    kind=std::stoi(*iterator1);
    iterator1++;
    manufactor=*iterator1;
    iterator1++;
    color =*(iterator1);
    iterator1++;




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






