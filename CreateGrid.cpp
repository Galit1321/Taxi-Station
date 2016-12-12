
#include "CreateGrid.h"
#include <stdlib.h>
#include <cstring>

/**
 * deconstructor
 */
CreateGrid::~CreateGrid() {

}
/**
 * constrctout
 * @param input
 * @return
 */
CreateGrid::CreateGrid(string &input) : Create(input) {
    for (std::list<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
     phase(*it);

}
//divide the input
void CreateGrid::phase(string s) {
    int pos=s.find(",");
    char tmp[100];
    try{
        int h=atoi(strcpy(tmp,s.substr(0,pos).c_str()));
        if ((h==0 )&&(s.substr(0,pos)!="0")){

            throw 'g';
        }
        this->input->push_back(h);
        s.erase(0, pos+1);
        this->input->push_back(atoi(strcpy(tmp,s.c_str())));;
    }catch (char e){
        cout<<"input numbers only between the _"<<endl;
        throw e;
    }


}

//return the params from theinput in a vector
vector<int>* &CreateGrid::getInput() {
    return input;
}
