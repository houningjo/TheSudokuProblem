//
//  Program3.cpp
//
//  Created by Ning Hou on 11/4/17.
//  Copyright © 2017 Ning Hou. All rights reserved.
//

#include "Puzzle.h"
#include <iostream>
using namespace std;

// constants
int UPPER_BOUND = 9;
int LOWER_BOUND = 1;

bool solve(int row, int col, Puzzle& thePuzzle){
    // base case: no more empty squares left
    if(thePuzzle.numEmpty() == 0){
        return true;
    }

    // move to next square without a value
    bool breakFromLoop = false;
    for(int i = 0; i < PUZZLE_LENGTH; i++){
        for(int j = 0; j < PUZZLE_LENGTH; j++){
            if(thePuzzle.get(i, j).getIsEmpty() == true){
                row = i;
                col = j;

                breakFromLoop = true;
                break;
            }
            
        }
        if(breakFromLoop){
            break;
        }

    }

    // for each value from 1 to 9,
    // check if it is legal to set number
    for(int num = LOWER_BOUND; num <= UPPER_BOUND; num++){
            // legal, set square to num
            
            if( thePuzzle.set(row, col, num)){
                // solve next row, col
                if(solve(row + 1, col, thePuzzle)){
                    
                    return true;
                }
            
                // failed to solve, erase square value
                else {
                    thePuzzle.set(row, col, 0);
                }
        }
    }
    
    return false;
}


int main(){
    
    Puzzle p;
    cin >> p;
    cout << "You've enter the following puzzle: ";
    cout << endl;
    cout << p;
    
    if(solve(0, 0, p) == true){

        cout << "Solved Sudoku: " << endl;
        cout << p;
    }
    else{
        cout << "Unable to solve this Sudoku." << endl;
    }

    
    return 0;
}




