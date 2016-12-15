//
// Created by michal on 12/1/16.
//

#include "Person.h"
/**
 * constructor
 * @return
 */

Person ::Person() {
    satisfaction =0;
    curr_pos =NULL;
}
/**
 * deconstructor
 * @return
 */
Person ::~Person() {

}

//get the curr pose of the passenger
Point *Person::getCurr_pos() const {
    return curr_pos;
}

//set the satisfaction of the passenger
void Person::setSatisfaction(float satisfaction) {
    Person::satisfaction = satisfaction;
}

//set the curr pose of the passenger
void Person::setCurr_pos(Point *curr_pos) {
    Person::curr_pos = curr_pos;
}


