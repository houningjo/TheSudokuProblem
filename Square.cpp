//
//  Square.cpp
//
//  Created by Ning Hou on 11/4/17.
//  Copyright © 2017 Ning Hou. All rights reserved.
//

/** The Square class creats a Square object that represents one square in the
 * sudoku puzzle.
 */

#include "Square.h"
#include <iostream>
#include <stdio.h>
using namespace std;

// constructors
/** Default constructor, sets this Square's value to 0 and isEmpty to true.
 */
Square::Square(){
    value = -1;
    isEmpty = true;
    isFixed = false;
}

/** Sets the value of this Square to the specified value n.
 * @param n the specified value to be set
 */
void Square::setValue(int n){
    value = n;
    if (n == 0) {
        isEmpty = true;
    }
    else{
        isEmpty = false;
    }
}

/**
 */
void Square::setIsFixed(bool target){
    isFixed = target;
}

/**
 */
bool Square::getIsFixed() const{
    return isFixed;
}

/** Returns true if this Square is empty, false otherwise.
 * @return bool true if this Square is empty, false otherwise.
 */
bool Square::getIsEmpty() const{
    return isEmpty;
}

/** Returns the value of this Square.
 * @return the value of this Square.
 */
int Square::getValue() const{
    return value;
}

/** test display
 */
void Square::toString() const{
    cout << "The value of this Square is: " << value << endl;
    cout << "This square is empty: " << isEmpty << endl;
}

