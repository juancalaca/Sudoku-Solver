// Project 4a
// seprod4a
//
// File: board.h
// This file contains the board class declaration with
// all its member function prototypes. This class reads
// a sudoku board from a file and stores it in a matrix container

#ifndef BOARD_CLASS
#define BOARD_CLASS

#include <iostream>
#include <iomanip>
#include <limits.h>
#include "d_matrix.h" // matrix container
#include "d_except.h"
#include <list>
#include <fstream>

class board
{
        
        public:
                board(int sqSize);
                // constructor initializes data members to fit
                // size of board specified by sqSize
        
                void clear();
                // sets all values in matrix value to -1
                // resets all conflicts for new board
        
                void initialize(ifstream &fin);
                // initializes matrix value with values read from file
        
                void print() const;
                // prints the current board
        
                bool isBlank(int i, int j) const;
                // returns true if cell(i,j) is in matrix value and is -1
        
                int getCell(int i, int j) const;
                // returns value in cell(i,j) if it is in matrix value
        
                void setCell(int i, int j, int val);
        
        
                void printConflicts() const;
                int squareNumber(int i, int j);
                bool isSolved() const;
                void resetCell(int i, int j);
        
        private:
                matrix<int> value;
                vector< vector<bool> > c_rows;
                vector< vector<bool> > c_cols;
                vector< vector<bool> > c_sqrs;
                int boardSize, sqSize;

};

#endif // BOARD_CLASS

// End of header file
