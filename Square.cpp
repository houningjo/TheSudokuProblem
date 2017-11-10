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
using namespace std;

// constructors
/** Default constructor, sets this Square's value to 0 and isEmpty to true.
*/
Square::Square(){
    value = 0;
    isEmpty = true;
}

/** Sets the value of this Square to the specified value n.
* @param n the specified value to be set
*/
void Square::setValue(int n){
    value = n;
    isEmpty = false;
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

/** Displays a string representation of this Square object.
*/
void Square::toString() const{
    cout << "The value of this Square is: " << value << endl;
    cout << "This square is empty: " << isEmpty << endl;
}
