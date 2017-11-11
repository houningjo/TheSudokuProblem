//
//  Puzzle.cpp
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
#include "Puzzle.h"
using namespace std;


Puzzle::Puzzle(){
}

/** Returns true if the specified value is not equal to any 
* value in the current block, false otherwise. 
* (x, y) is the location of the left corner of the current Block. 
* @pre value must be in range from 0 to 9.
* @param x the column number of the loction of the left corner
* @param y the row number of the loction of the left corner
* @param value the specified value
* @return bool true if the specified value is not equal to any
* value in the current block, false otherwise
*/
bool Puzzle::isBlockLegal(int y, int x, int value){
    for(int row = y; row < 3; row++){
        for(int col = x; col < 3; col++){
            if(puzzleTable[row][col].getValue() == value){
                return false;
            }
        }
    }
    return true;
}

/** Returns true if the specified value is not equal to any value
* in the current row, false otherwise.
* @pre value must be in range from 0 to 9.
* @param y the row number of the current row
* @param value the specified value
* @return bool true if the specifed value is not equal to any value
* in the current row, false otherwise
*/
bool Puzzle::isRowLegal(int y, int x, int value){

    for(int col = 0; col < PUZZLE_LENGTH; col++){
        if(puzzleTable[y][col].getValue() == value){
            return false;
        }
    }
    return true;
}

/** Returns false if the specified value is not equal to any value
* in the current column, false otherwise.
* @pre value must be in range from 0 to 9.
* @param x the column number of the current colunmn
* @param value the specified value
* @return bool true if the specified value is not equal to any value
* in the current column, false otherwise
*/
bool Puzzle::isColumnLegal(int y, int x, int value){
    for(int row = 0; row < PUZZLE_LENGTH; row++){
        if(puzzleTable[row][x].getValue() == value){
            return false;
        }
    }
    return true;
}

/** Returns a const reference to the square at the specified location.
* @param x the column number
* @param y the row number
* @return Square& 
*/
const Square& Puzzle::get(int y, int x){
    return puzzleTable[y][x];
}

/** Returns the number of variable entries in the origianl Puzzle.
* @return int the number of variable entries in this Puzzle
*/
int Puzzle::size() const{
    return emptyVarCount;
}

/** Returns the number of empty Squares remains in this Puzzle.  
* @return int the number of empty Squares. 
*/
int Puzzle::numEmpty() const{
    return remainVarCount;
}

/** Return true if the specified value is not euqal to any value
* in the same row, column, and block, false otherwise.
* To calculate the location of the left corner of the current block,
* blockX = (x / 3) * 3, blockY = (y / 3) * 3.
* @pre value must be in range from 0 to 9.
* @param x the column number of the current column
* @param y the row number of the current row
* @param value the specified value
* @return bool true if the specifed value is not equal to any value
* in the same row, column, and block, false othewise. 
*/
bool Puzzle::isLegal(int y, int x, int value){
    // always legal to set it to 0 unless it's fixed
    if(puzzleTable[y][x].getIsFixed() == true){
        return false;
    }
    if(value == 0){
        return true;
    }
    else{
        // calculate the location of the left corner in the current block
        int blockX = (x / 3) * 3;
        int blockY = (y / 3) * 3;
        // check row, col, block
        return isRowLegal(y, x, value)
            && isColumnLegal(y, x, value)
            && isBlockLegal(blockY, blockX, value);
    }
    return true;
}

/** Returns true if sucessfully set the specified value at the 
* specified location, false otherwise.
* Precondition: value must be legal before set. 
* Retruns false if value is illegal. 
* @pre value must be in range from 0 to 9. 
* @param x the column number of the specified location
* @param y the row number of the specified location
* @param value the specified value
* @return bool true if successfully set the specified value at
* the specified location, false otherwise
*/
bool Puzzle::set(int y, int x, int value){
    
    // check value is in range
    if(value < 0 || value > 9){
        throw out_of_range("value is out of range.");
    }
    // if not legal or is a fixed number, set fails
    if(!isLegal(x, y, value) ||
       puzzleTable[y][x].getIsFixed() == true){
        return false;
    }
    else{
        // update remaining empty squares
        // remain number is not updating correctly
        if(value == 0){
            remainVarCount++;
        }
        else if(puzzleTable[y][x].getIsFixed() == false){
            remainVarCount--;
        }
        puzzleTable[y][x].setValue(value);
    }
    
    return true;
}

/** Reads input from istream and stores it in a 2D array of Squares.
* @param input an istream input reference
* @param thePuzzle reference of this Puzzle 
* @return istream& the processed istream
*/
istream & operator >>(istream& input, Puzzle& thePuzzle){
    
    // input can't ignore non digit - bug
    for(int row = 0; row < 9; row++){
        for(int col = 0; col < 9; col++){
            char temp = input.get();
            if(temp < '0' || temp > '9'){
                temp = input.get();
            }
            else if(temp == '\n' || temp == '\r'){
            }
            else{
                int i = temp - '0';
                // update emptyVarCount
                if(i == 0){
                    thePuzzle.emptyVarCount++;
                }
                //thePuzzle.puzzleTable[row][col].setValue(i);
                thePuzzle.set(row, col, i);    // set does not work
                thePuzzle.puzzleTable[row][col].setIsFixed(true);
            }

        }
    }

    return input;
}

/** Returns a string representation of the Puzzle.
* @param output an ostream output reference
* @param thePuzzle reference of this Puzzle 
* @return string a string representation of the Puzzle.
*/
ostream& operator <<(ostream& output, Puzzle& thePuzzle){
    string line = "+-----------------------+";
    cout << line << endl;
    int rowCounter = 0;
    int colCounter = 0;
    for(int row = 0; row < PUZZLE_LENGTH; row++){
        cout << "| ";
        for(int col = 0; col < PUZZLE_LENGTH; col++){
            cout << thePuzzle.puzzleTable[row][col].getValue() << " ";
            rowCounter++;
            if(rowCounter == 3){
                cout << "| ";
                rowCounter = 0;
            }
        }
        cout << endl;
        colCounter++;
        if(colCounter == 3){
            cout << line << endl;
            colCounter = 0;
        }
        
    }
    
    return output;
}


