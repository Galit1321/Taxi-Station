//
// Created by galit on 12/12/16.
//

#include "CreateDriver.h"

CreateDriver::CreateDriver(string &input) : Create(input) {
    int id;
    int age;
    string stat;
    int exp;
    int vehicle_id;
    if (this->tokens.size()!=5){
        return ;
    }
    list<string>::iterator iterator1=this->tokens.begin();
    id=atoi(*iterator1);
    iterator1++;
    age=atoi(*iterator1);
    iterator1++;
    stat=*(iterator1);
    iterator1++;
    exp=atoi(*iterator1);
    iterator1++;
    vehicle_id=atoi(*iterator1);
    driver=new Driver(id,age,exp,stat);
}
