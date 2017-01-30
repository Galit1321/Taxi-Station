
#include "CreateGrid.h"
#include <stdlib.h>
#include <cstring>

/**
 * deconstructor
 */
CreateGrid::~CreateGrid() {

}
/**
 * constructor
 * @param input
 * @return
 */
CreateGrid::CreateGrid(string &input) : Create(input) {
    if(tokens.size()!=2){
        work = false;
        return ;
    }
    for (std::list<string>::iterator it = tokens.begin(); it != tokens.end(); it++){
        if (((*it).find_first_not_of("0123456789")!= std::string::npos)){
            work = false;
        }
        int h=stoi((*it));
        this->input.push_back(h);
    }

}


//return the params from theinput in a vector
vector<int> &CreateGrid::getInput() {
    return input;
}