
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
    input.push_back(std::stoi(*it));

}


//return the params from theinput in a vector
vector<int>* &CreateGrid::getInput() {
    return input;
}
