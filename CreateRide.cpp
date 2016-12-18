

#include "CreateRide.h"

CreateRide::~CreateRide() {

}

//set the parameters of the ride
CreateRide::CreateRide(string &input) : Create(input) {
    if (this->tokens.size()!=7){
        return ;
    }
    list<string>::iterator iterator1=this->tokens.begin();
    id=std::stoi(*iterator1);
    iterator1++;
    start_x=std::stoi(*iterator1);
    iterator1++;
    star_y=std::stoi(*iterator1);
    iterator1++;
    end_x=std::stoi(*iterator1);
    iterator1++;
    end_y=std::stoi(*iterator1);
    iterator1++;
    numOfPass=std::stoi(*iterator1);
    iterator1++;
    tariff=std::stod(*iterator1);

}



