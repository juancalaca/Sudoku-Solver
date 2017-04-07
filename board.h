// Project 4b
// seprod4b
//
// File: board.h
// This file contains the board class declaration with all its member
// function prototypes. This class reads a sudoku board from a file
// and stores it in a matrix container.
// Given the conventional sudoku board rules, this class counts
// the conflicts present in the board in a vector of boolean vectors.
// As data members, this class stores a vector of boolean vectors for
// rows, columns, and squares of the board. The boolean vector at index i
// represents the state of row/column/square i, where the index s of the
// boolean vector represents if the value s is in that row/column/square i.
// This class solves the sudoku board using function solve() where it solves
// the board recursively, as well as using backtracking. Together with the conflict
// matrices for the board, and the function findMostConstrainedCell() the
// number of recursive calls is optimized.


#ifndef BOARD_CLASS
#define BOARD_CLASS

#include <iostream>
#include <iomanip>
#include <limits.h>
#include "d_matrix.h" // matrix container
#include "d_except.h"
#include <fstream>

using namespace std;

class board
{
        
        public:
                board(int sqSize);
                // constructor initializes data members to size of board specified by sqSize
        
                void clear();
                // sets all values in matrix value to -1
                // resets all conflicts for new board
        
                void initialize(ifstream &fin);
                // initializes matrix value with values read from file
        
                void print() const;
                // prints the current board
        
                bool isBlank(int i, int j) const;
                // returns true if cell(i,j) is in matrix and value is -1
        
                int getCell(int i, int j) const;
                // returns value in cell(i,j) if it is within matrix value range
        
                void setCell(int i, int j, int val);
                // sets a value in cell (i,j) if it is within matrix value range
                // updates conflicts for val in cell (i,j)
        
                void printConflicts() const;
                // prints conflicts of legal values for each row, column, square
        
                int squareNumber(int i, int j);
                // returns square number where cell (i,j) is in if cell in matrix
        
                bool isSolved() const;
                // returns true if all cells are filled, false otherwise
        
                void resetCell(int i, int j);
                // sets value of cell (i,j) to blank
                // updates conflicts for blank cell (i,j)
        
                void findFirstBlankCell(int& i, int& j);
                //finds the first blank cell in the board
        
                bool isLegal(int i, int j, int s);
                //returns if the number can be placed in the cell
        
                void solve(long long int& recursiveCalls);
                //solves the board recursively with backtracking
        
                void findMostConstrainedCell(int& i, int& j);
                //finds blank cell with most constrains relative to other blank cells
        
                static bool isTrue(bool i) {return i == true;};
                //static function to help count the number of booleans 'true's in the vector
        
        private:
                matrix<int> value;
                // matrix object to hold values of board
        
                vector<vector<bool> > c_rows;
                vector<vector<bool> > c_cols;
                vector<vector<bool> > c_sqrs;
                // vectors of boolean vectors that hold the conflicts of the current board
                // one vector for rows, columns, squares
                // boolean vector at index s holds state of value s in row/column/square i
                // if true: value in row/square/column false: value not in r/s/c
        
                int boardSize, sqSize;
                // data members that hold values pertaining to the size of the board
        
};

#endif // BOARD_CLASS

// End of header file
