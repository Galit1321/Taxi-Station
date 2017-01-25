
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
CreateGrid::CreateGrid(string &input) : Create(input) { ;
    for (std::list<string>::iterator it = tokens.begin(); it != tokens.end(); it++){
        int h=stoi((*it));
        this->input.push_back(h);
    }


}


//return the params from theinput in a vector
vector<int> &CreateGrid::getInput() {
    return input;
}
