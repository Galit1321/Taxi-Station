

#include "CreateRide.h"

CreateRide::~CreateRide() {

}

//set the parameters of the ride
CreateRide::CreateRide(string &input,int h,int w) : Create(input) {
    if (this->tokens.size()!=8){
        work = false ;
    }
    list<string>::iterator iterator1=this->tokens.begin();
    if (((*iterator1).find_first_not_of("0123456789")!= std::string::npos)||((*iterator1) == "0")){
        work = false;
    }
    id=std::stoi(*iterator1);
    iterator1++;
    if (((*iterator1).find_first_not_of("0123456789") != std::string::npos)){
        work = false;
    }
    start_x=std::stoi(*iterator1);
    if(start_x<=w){
        work = false;
    }
    iterator1++;
    if (((*iterator1).find_first_not_of("0123456789") != std::string::npos)){
        work = false;
    }
    star_y=std::stoi(*iterator1);
    if(star_y<=h){
        work = false;
    }
    iterator1++;
    if (((*iterator1).find_first_not_of("0123456789") != std::string::npos)){
        work = false;
    }
    end_x=std::stoi(*iterator1);
    if(end_x<=w){
        work = false;
    }
    iterator1++;
    if (((*iterator1).find_first_not_of("0123456789") != std::string::npos)){
        work = false;
    }
    end_y=std::stoi(*iterator1);
    if(end_y<=h){
        work = false;
    }
    iterator1++;
    if (((*iterator1).find_first_not_of("0123456789") != std::string::npos)||((*iterator1) == "0")){
        work = false;
    }
    numOfPass=std::stoi(*iterator1);
    iterator1++;
    if (((*iterator1).find_first_not_of("0123456789") != std::string::npos)||((*iterator1) =="0")){
        work = false;
    }
    tariff=std::stod(*iterator1);
    iterator1++;
    if (((*iterator1).find_first_not_of("0123456789") != std::string::npos)||((*iterator1) == "0")){
        work = false;
    }
    time=std::stoi(*iterator1);

}



