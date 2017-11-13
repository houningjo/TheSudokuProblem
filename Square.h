//
//  Square.h
//
//  Created by Ning Hou on 11/4/17.
//  Copyright © 2017 Ning Hou. All rights reserved.
//

/** The Square class creats a Square object that represents one square in the
 * sudoku puzzle.
 */

#pragma once
#include <stdio.h>

class Square{
    
private:
    int value = 0;
    bool isEmpty = true;
    bool isFixed = false;
    friend class Puzzle;

protected:
    /** Sets the value of this Square to the specified value n.
     * @param n the specified value to be set
     */
    void setValue(int n);

public: 
    // constructors
    /** Default constructor, sets this Square's value to 0 and isEmpty to true.
     */
    Square();

    /** Sets the flag of it is fixed to the specified value target.
     * @param target the specified value
     */
    void setIsFixed(bool target);
    
    /** Sets the flag of it is empty to the specified value target.
     * @param target the specified value
     */
    void setIsEmpty(bool target);
    
    /**
     */
    bool getIsFixed() const;
    
    /** Returns true if this Square is empty, false otherwise.
     * @return bool true if this Square is empty, false otherwise.
     */
    bool getIsEmpty() const;
    
    /** Returns the value of this Square.
     * @return the value of this Square.
     */
    int getValue() const;
    
    /** display a string representation of this Square.
     */
    void toString() const;
};

