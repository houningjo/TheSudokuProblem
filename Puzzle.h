//
//  Puzzle.h
//
//  Created by Ning Hou on 11/4/17.
//  Copyright © 2017 Ning Hou. All rights reserved.
//

/** The Puzzle class creates a Puzzle object that is made of
 * 9-by-9 Squares.
 */

#pragma once
#include <stdio.h>
#include <iostream>
#include "Square.h"
using namespace std;

const int PUZZLE_LENGTH = 9;
const int BLOCK_LENGTH = 3;


class Puzzle{
    
private:
    Square puzzleTable[PUZZLE_LENGTH][PUZZLE_LENGTH];
    int emptyVarCount;    // number of empty variables after reading in an input
    int remainVarCount;    // number of empty variables remains
    //friend Square;
    
public:
    Puzzle();
    
    /** Returns true if the specified value is not equal to any
     * value in the current block, false otherwise.
     * (row, col) is the location of the left corner of the current Block.
     * @pre value must be in range from 0 to 9.
     * @param row the row number of the loction of the left corner
     * @param col the column number of the loction of the left corner
     * @param value the specified value
     * @return bool true if the specified value is not equal to any
     * value in the current block, false otherwise
     */
    bool isBlockLegal(int row, int col, int value);
    
    /** Returns true if the specified value is not equal to any value
     * in the current row, false otherwise.
     * @pre value must be in range from 0 to 9.
     * @param row the row number of the current row
     * @param value the specified value
     * @return bool true if the specifed value is not equal to any value
     * in the current row, false otherwise
     */
    bool isRowLegal(int row, int value);
    
    /** Returns false if the specified value is not equal to any value
     * in the current column, false otherwise.
     * @pre value must be in range from 0 to 9.
     * @param col the column number of the current colunmn
     * @param value the specified value
     * @return bool true if the specified value is not equal to any value
     * in the current column, false otherwise
     */
    bool isColumnLegal(int col, int value);
    
    /** Returns a const reference to the square at the specified location.
     * @param row the row number
     * @param col the column number
     * @return Square&
     */
    const Square& get(int row, int col);
    
    /** Returns the number of variable entries in the origianl Puzzle.
     * @return int the number of variable entries in this Puzzle
     */
    int size() const;
    
    /** Returns the number of empty Squares remains in this Puzzle.
     * @return int the number of empty Squares.
     */
    int numEmpty() const;
    
    /** Return true if the specified value is not euqal to any value
     * in the same row, column, and block, false otherwise.
     * To calculate the location of the left corner of the current block,
     * blockX = (x / 3) * 3, blockY = (y / 3) * 3.
     * @pre value must be in range from 0 to 9.
     * @param row the row number of the current column
     * @param col the col number of the current row
     * @param value the specified value
     * @return bool true if the specifed value is not equal to any value
     * in the same row, column, and block, false othewise.
     */
    bool isLegal(int row, int col, int value);
    
    /** Returns true if sucessfully set the specified value at the
     * specified location, false otherwise.
     * Precondition: value must be legal before set.
     * Retruns false if value is illegal.
     * @pre value must be in range from 0 to 9.
     * @param row the row number of the specified location
     * @param col the column number of the specified location
     * @param value the specified value
     * @return bool true if successfully set the specified value at
     * the specified location, false otherwise
     */
    bool set(int row, int col, int value);

    /** Reads input from istream and stores it in a 2D array of Squares.
     * @param input an istream input reference
     * @param thePuzzle reference of this Puzzle
     * @return istream& the processed istream
     */
    
    /**
     */
    void initial(int row, int col, int value);
    
    friend istream & operator >>(istream& input, Puzzle& thePuzzle);

    /** Returns a string representation of the Puzzle.
     * @param output an ostream output reference
     * @param thePuzzle reference of this Puzzle
     * @return string a string representation of the Puzzle.
     */
    friend ostream& operator <<(ostream& output, Puzzle& thePuzzle);

};

