#include <iostream>
#include "string.h"
#include "Create.h"
/**
 * deconstructor
 */
Create::~Create() {
    tokens.clear();

}
/**
 *
 * @param input  the string we want to divided
 * @return
 */
Create::Create(string &input){
    size_t pos = 0;
    while ((pos = input.find(",")) != string::npos) {
        tokens.push_back(input.substr(0, pos));
        input.erase(0, pos +1);

    }
    tokens.push_back(input.substr(0, pos));
    tokens.push_back(input);
}
/**
 * default constructor
 * @return
 */
Create::Create() {
// tokens=new deque<string>();
}
/**
 * getter of tokens
 * @return this->tokens
 */
list<string>  Create::getTokens() const {
    return tokens;
}




