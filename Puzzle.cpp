//
//  Puzzle.cpp
//
//  Created by Ning Hou on 11/4/17.
//  Copyright © 2017 Ning Hou. All rights reserved.
//

/** The Puzzle class creates a Puzzle object that is made of
 * 9-by-9 Squares.
 */

#include <stdio.h>
#include <iostream>
#include "Puzzle.h"
using namespace std;


Puzzle::Puzzle(){
}

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
bool Puzzle::isBlockLegal(int row, int col, int value){
    for(int i = row; i < row + BLOCK_LENGTH; i++){
        for(int j = col; j < col + BLOCK_LENGTH; j++){
            if(puzzleTable[i][j].getValue() == value){
                cout << "square value: " << puzzleTable[i][j].getValue() << endl;
                cout << "block legal value: " << value << endl;
                return false;
            }
        }
    }
    return true;
}

/** Returns true if the specified value is not equal to any value
 * in the current row, false otherwise.
 * @pre value must be in range from 0 to 9.
 * @param row the row number of the current row
 * @param value the specified value
 * @return bool true if the specifed value is not equal to any value
 * in the current row, false otherwise
 */
bool Puzzle::isRowLegal(int row, int value){

    for(int col = 0; col < PUZZLE_LENGTH; col++){
        if(puzzleTable[row][col].getValue() == value){
            return false;
        }
    }
    return true;
}

/** Returns false if the specified value is not equal to any value
 * in the current column, false otherwise.
 * @pre value must be in range from 0 to 9.
 * @param col the column number of the current colunmn
 * @param value the specified value
 * @return bool true if the specified value is not equal to any value
 * in the current column, false otherwise
 */
bool Puzzle::isColumnLegal(int col, int value){
    for(int row = 0; row < PUZZLE_LENGTH; row++){
        if(puzzleTable[row][col].getValue() == value){
            return false;
        }
    }
    return true;
}

/** Returns a const reference to the square at the specified location.
 * @param row the row number
 * @param col the col number
 * @return Square&
 */
const Square& Puzzle::get(int row, int col){
//    Square* temp;
//    temp -> puzzleTable[y][x];
    return puzzleTable[row][col];
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
 * @param row the row number of the current column
 * @param col the col number of the current row
 * @param value the specified value
 * @return bool true if the specifed value is not equal to any value
 * in the same row, column, and block, false othewise.
 */
bool Puzzle::isLegal(int row, int col, int value){
    // always legal to set it to 0 unless it's fixed
    if(puzzleTable[row][col].getIsFixed() == true){
        return false;
    }
    if(value == 0){
        return true;
    }
    //else{
        // calculate the location of the left corner in the current block
        int blockCol = (col / 3) * 3;
        int blockRow = (row / 3) * 3;
        // check row, col, block
        return isRowLegal(row, value)
            && isColumnLegal(col, value)
            && isBlockLegal(blockRow, blockCol, value);
    //}
    //return true;
}

/** Returns true if sucessfully set the specified value at the
 * specified location, false otherwise.
 * throws an out of range exception if value is less than 0
 * and greater than 9.
 * Precondition: value must be legal before set.
 * Retruns false if value is illegal.
 * @pre value must be in range from 0 to 9.
 * @param row the row number of the specified location
 * @param col the column number of the specified location
 * @param value the specified value
 * @return bool true if successfully set the specified value at
 * the specified location, false otherwise
 */
bool Puzzle::set(int row, int col, int value){
    
    // check value is in range
    if(value < 0 || value > 9){
        throw out_of_range("value is out of range.");
    }
    // if not legal or is a fixed number, set fails
    if(isLegal(row, col, value) == false ||
       puzzleTable[row][col].getIsFixed() == true){
        cout << "either is not legal or is fixed number. " << endl;
        return false;
    }
    //else{
        // update remaining empty squares
        // remain number is not updating correctly

    puzzleTable[row][col].setValue(value);
    
    if(value == 0){
        remainVarCount++;
        puzzleTable[row][col].setIsEmpty(true);
    }
    else{
        remainVarCount--;
        puzzleTable[row][col].setIsEmpty(false);
    }
    
        // if it's reading in a number for the first time
//        if(temp.getValue() == -1 || value == 0){
//
//            puzzleTable[row][col].setValue(value);
//            if ( value == 0)
//            {
//                remainVarCount++;
//            }
//            else{
//                remainVarCount--;
//            }
//
//        }
        // if it's changing values
        /*else if(temp.getValue() != -1){
            // set value from non 0 to 0
            if(value == 0){
                //cout << "here??" << endl;
                remainVarCount++;
            }
            else{
                remainVarCount--;
            }
        }*/
        
       // cout << "value: " << value << endl;
        //puzzleTable[row][col].setValue(value);
        
   // }
    
    
    return true;
}


/**
 */
void Puzzle::initial(int row, int col, int value){

    puzzleTable[row][col].setValue(value);
    // update num empty
    if(value == 0){
        remainVarCount++;
    }
    
}

/** Reads input from istream and stores it in a 2D array of Squares.
 * @param input an istream input reference
 * @param thePuzzle reference of this Puzzle
 * @return istream& the processed istream
 */
istream & operator >>(istream& input, Puzzle& thePuzzle){
    
    // input can't ignore non digit - bug
    for(int row = 0; row < PUZZLE_LENGTH; row++){
        for(int col = 0; col < PUZZLE_LENGTH; col++){
            char temp = input.get();
            if(temp < '0' || temp > '9'){
                break;
            }
            if(temp >= '0' && temp <= '9' ){
                int i = temp - '0';

                thePuzzle.initial(row, col, i);
                //cout << "i: " << i << endl;
                // update emptyVarCount
                if(i == 0){
                    thePuzzle.emptyVarCount++;
                    thePuzzle.puzzleTable[row][col].setIsEmpty(true);
                    thePuzzle.puzzleTable[row][col].setIsFixed(false);
                    //cout<< row <<" " <<col <<"is it fixed: " << thePuzzle.puzzleTable[row][col].getIsFixed() << endl;
                }
                else{
                //
                    // set does not work
                    thePuzzle.puzzleTable[row][col].setIsEmpty(false);
                    thePuzzle.puzzleTable[row][col].setIsFixed(true);
                    //cout<< row <<" " <<col <<"is it fixed: " << thePuzzle.puzzleTable[row][col].getIsFixed() << endl;
                }
                
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
    string midLine = "|-------+-------+-------|";
    cout << line << endl;
    int rowCounter = 0;
    int colCounter = 0;
    int midDivCounter = 0;
    
    for(int row = 0; row < PUZZLE_LENGTH; row++){
        cout << "| ";
        for(int col = 0; col < PUZZLE_LENGTH; col++){
            cout << thePuzzle.puzzleTable[row][col].getValue() << " ";
            colCounter++;
            if(colCounter == BLOCK_LENGTH){
                cout << "| ";
                colCounter = 0;
            }
        }
        cout << endl;

        rowCounter++;
        if(rowCounter == BLOCK_LENGTH && midDivCounter < BLOCK_LENGTH - 1){
            cout << midLine << endl;
            rowCounter = 0;
            midDivCounter++;
        }
        
        
    }
    
    cout << line << endl;
    
    return output;
}



