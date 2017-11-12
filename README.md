Designing a Sudoku Class and Implementing Backtracking
Learning Goals

Develop a better understanding of recursion as a problem solving strategy
Explore backtracking as a specific example of a recursive strategy
Design and compose multiple datatypes to build a solution
Apply a systematic analysis, design, and implementation process to a larger problem
In this assignment, you will design and implement a class to represent Sudoku puzzles. You will then use this class to implement a basic backtracking solver. This is a substantial assignment and you will need to take full advantage of the two weeks available to you. In particular, you will want to make sure that you've worked out detailed information for your classes, methods, and major algorithms by the design due date!

Sudoku

Sudoku (Links to an external site.)Links to an external site. is a type of puzzle that originated in Japan and has attracted a worldwide following, appearing in newspapers, books, and web sites. It is very simple: a 9-by-9 arrangement of squares, subdivided into 3-by-3 blocks. A particular puzzle comes with a subset of the squares filled in with numbers from 1 through 9. To solve the puzzle, one must only fill in all the blank squares with numbers from 1 through 9 so that no row, column, or 3-by-3 block in the puzzle has the same number twice. That's all there is to it!

Puzzle and Square Classes

In this program, you are asked to design and implement a representation for a Sudoku puzzle. You will use this to implement a program that solves such puzzles using a basic backtracking algorithm. More specifically, you must implement the following classes:

Your Puzzle class must hold the representation of a puzzle. It does this by holding Square objects. It also enforces constraints among the squares in a row, column, or block.

A Square object holds all of the information associated with one location in the puzzle. This includes the square's numerical value and a flag indicating if the value is fixed (one of the ones given at the start of the puzzle) or variable (the ones written in as parts of a possible solution). The minimal interface for the Square class is (you need to figure out the parameters and return types):

getValue() Returns the current value (-1 if no value set).
setValue() Takes a single integer argument; sets the value to the given argument. Since this method does not enforce any constraints among the values in the same row, column, or block, this method should not be public. Make it protected and declare Puzzle as a friend. The implication is that, while any code could read the value of a square, only a puzzle will set its value, after checking constraints to ensure it is legal.
At a minimum, you must implement the following interface for your Puzzle class:

operator>>() Overload the stream input operator to read puzzles in a compact format. The format consists of a sequence of 81 numerical digits, as ASCII text, each corresponding to the contents of one square in the puzzle grid, in row-major order (i.e., starting at the upper left corner, reading across each row and then continuing with the next row, ending at the bottom right corner). Blank squares are represented with zeros. Your operator should ignore all non-digit characters (i.e., scan the input character by character and use the first 81 ASCII characters in the set {0, 1, ..., 9} found). While you may separate numbers with white space on output, your input operator should not assume that white space separates them (i.e., it should work with an input that consists of only 81 characters). Inputting a puzzle should set all of its component squares' values correctly. Remember that the stream I/O operators are not methods of the Puzzle class!
get() This method takes two integer arguments ((x,y) location, zero-based) and returns a const reference to the square at that location.
set() This method takes three integer arguments ((x,y) location and value) and attempts to set the value of the square at that location to the given value. It will only succeed if the value proposed is legal for that square (i.e., does not duplicate a value in the same row, column, or block). If set() succeeds, the indicated square's value is updated and this method returns true. If set() fails, it returns false.
operator<<() Your class should also support a "human friendly" display via the stream output operator. We're not going to go to the trouble of producing a graphical user interface, so the display of a puzzle should be formatted text. Output a puzzle as 11 lines of text, with each line containing the numbers in a row of the puzzle separated by single spaces. Use the '|', '+', and '-' characters to separate 3-by-3 blocks (so, each line of output should be 19 printing characters long: 9 digits, 8 spaces, and 2 '|' for "non-divider" lines and 17 '-' and 2 '+' for "divider" lines).
size() This should return the number of variable entries in the puzzle, corresponding to the original size of the puzzle (before any blank squares are filled in).
numEmpty() This method should return the number of empty squares (those without any value).
Statement of Work

Write a program that creates a Puzzle object and reads a Sudoku puzzle from cin. It should then display the original puzzle. Your program should then apply a backtracking algorithm to solve the puzzle. A simple outline of such an algorithm might be:

Solve(row, column)
   if (row, column) past end of puzzle, return success
   Move to next square without a value
   foreach value from 1 through 9
      if value is legal, set square to it
         if Solve(next row and column) succeeds
            return success
         endif
         erase square value
      endif
   endfor
   return failure
end Solve
Your program should then display the solved puzzle or, if it couldn't be solved, output a message to indicate so.
