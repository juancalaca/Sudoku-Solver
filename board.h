#ifndef BOARD_CLASS
#define BOARD_CLASS

#include <iostream>
#include <iomanip>
#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <list>
#include <fstream>

class board
{
public:
        board(int sqSize);
        void clear();
        void initialize(ifstream &fin);
        void print() const;
        bool isBlank(int i, int j) const;
        int getCell(int i, int j) const;
        void setCell(int i, int j, int val);
        void setConflicts();
        void printConflicts() const;
        int squareNumber(int i, int j);
        bool isSolved() const;
        void place(int i, int j, int val);
        void remove(int i, int j);
        
private:
        matrix<int> value;
        vector< vector<bool>> c_rows;
        vector< vector<bool>> c_cols;
        vector< vector<bool>> c_sqrs;
        int boardSize, sqSize;
        //matrix< vector<int>> tally;

};

#endif