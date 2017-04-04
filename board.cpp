// Project 4a
// seprod4a
//
// File: board.cpp
// This file contains the declaration of class board's
// member functions.

#include "board.h" // include function prototypes

// constructor initializes data members to appropriate size
// given value of parameter sqSz
board::board(int sqSz) : sqSize(sqSz)
{
        // board size is the square of sqSizw
        boardSize = sqSize * sqSize;
        
        // matrix goes from 1 to boardSize
        // start indexing at 1
        value.resize(boardSize + 1, boardSize + 1);
        
        // resize vector to fit all rows/cols/sqrs
        // start indexing at 1
        c_rows.resize(boardSize + 1);
        c_cols.resize(boardSize + 1);
        c_sqrs.resize(boardSize + 1);
        
        // resize all boolean vectors to fit s values
        // given by the size of the board
        // start indexing at 1
        for (int i = 1; i <= boardSize; i++)
        {
                c_rows[i].resize(boardSize + 1);
                c_cols[i].resize(boardSize + 1);
                c_sqrs[i].resize(boardSize + 1);
        }
}


void board::clear()
//clears the board, sets all values to blank (-1)
{
        for (int i = 1; i <= boardSize; i++)
        {
                for (int j = 1; j <= boardSize; j++)
                {
                        value[i][j] = -1;
                }
        }

	for (int i = 1; i <= boardSize; i++)
	{
		for (int j = 1; j <= boardSize; j++)
		//initializes all of the conflicts to false to avoid mistakes when looping
		{
			c_rows[i][j] = false;
			c_cols[i][j] = false;
			c_sqrs[i][j] = false;
		}
	}
}

void board::initialize(ifstream &fin)
//initializes the board, creates the board by setting '.' to blank cells
//and non '.' characters to the number provided
{
        char ch;
        
        clear();
        
        for (int i = 1; i <= boardSize; i++)
        {
                for (int j = 1; j <= boardSize; j++)
                {
                        fin >> ch;
                        
                        if (ch != '.')
                                setCell(i, j, ch - '0');
                                //turns the character to an int
                }
        }
        
}

void board::print() const
// Prints the current board.
{
        for (int i = 1; i <= boardSize; i++)
        {
                if ((i-1) % sqSize == 0)
                {
                        cout << " -";
                        for (int j = 1; j <= boardSize; j++)
                                cout << "---";
                        cout << "-";
                        cout << endl;
                }
                for (int j = 1; j <= boardSize; j++)
                {
                        if ((j-1) % sqSize == 0)
                                cout << "|";
                        if (!isBlank(i,j))
                                cout << " " << getCell(i,j) << " ";
                        else
                                cout << "   ";
                }
                cout << "|";
                cout << endl;
        }
        
        cout << " -";
        for (int j = 1; j <= boardSize; j++)
                cout << "---";
        cout << "-";
        cout << endl;
}

bool board::isBlank(int i, int j) const
//checks if the current board is blank, that is there are no values in any
//of the cells
{
        if (i < 1 || i > boardSize || j < 1 || j > boardSize)
                throw rangeError("bad value in isBlank");
        
        return (getCell(i,j) == -1);
}

int board::getCell(int i, int j) const
//gets the value from a specific cell, or throws an error if the cell does not exist
{
        if (i >= 1 && i <= boardSize && j >= 1 && j <= boardSize)
                return value[i][j];
        else
                throw rangeError("bad value in getCell");
}

void board::setCell(int i, int j, int val)
//sets a cell to a given value and updates the conflicts accordingly
{
        if (i >= 1 && i <= boardSize && j >= 1 && j <= boardSize)
                value[i][j] = val;
        else
                throw rangeError("bad value in setCell");
        
        int sqrNum = squareNumber(i, j);
        c_rows[i][val] = true;
        c_cols[j][val] = true;
        c_sqrs[sqrNum][val] = true;
}

void board::printConflicts() const
//prints the matrices of all of the conflicts for the rows, columns and squares
{
        cout << noboolalpha;
        cout << "Column Conflicts" << endl;
        for (int i = 1; i <= boardSize; i++)
        {
                cout << "Column " << i << ": ";
                for (int j = 1; j <= boardSize; j++)
                {
                      cout << c_cols[i][j] << " ";
                }
                cout << endl;
        }
        cout << endl;
        cout << "Row Conflicts" << endl;
        for (int i = 1; i <= boardSize; i++)
        {
                cout << "Row " << i << ": ";
                for (int j = 1; j <= boardSize; j++)
                {
                        cout << c_rows[i][j] << " ";
                }
                cout << endl;
        }
        cout << endl;
        cout << "Square Conflicts" << endl;
        for (int i = 1; i <= boardSize; i++)
        {
                cout << "Square " << i << ": ";
                
                for (int j = 1; j <= boardSize; j++)
                {
                        cout << c_sqrs[i][j] << " ";
                }
                cout << endl;
        }
}

int board::squareNumber(int i, int j)
// Return the square number of cell i,j (counting from left to right,
// top to bottom.  Note that i and j each go from 1 to BoardSize
{
        // Checks if cell within range of matrix value
        if (i < 1 || i > boardSize || j < 1 || j > boardSize)
                throw rangeError("bad value in squareNumber");
        
        // Note that (int) i/SquareSize and (int) j/SquareSize are the x-y
        // coordinates of the square that i,j is in.
        return sqSize * ((i-1)/sqSize) + (j-1)/sqSize + 1;
}

bool board::isSolved() const
//checks if the board is solved, (opposite of isBlank()) by seeing if there is a 
//value placed in every cell
{
        for (int i = 1; i <= boardSize; i++)
        {
                for (int j = 1; j <= boardSize; j++)
                {
                        if (value[i][j] == -1)
                                return false;
                }
        }
        return true;
}

void board::resetCell(int i, int j)
//resets a cell or throws an error if trying to access invalid cell
//updates the conflicts accordingly
{
        int val = value[i][j];
        
        if (i >= 1 && i <= boardSize && j >= 1 && j <= boardSize)
                value[i][j] = -1;
        else
                throw rangeError("bad value in resetCell");
        
        int sqrNum = squareNumber(i, j);
        c_rows[i][val] = false;
        c_cols[j][val] = false;
        c_sqrs[sqrNum][val] = false;

}

void board::findFirstBlankCell(int& i, int& j)
{
        int val;
        for (int r = 1; r <= boardSize; r++)
        {
                for (int c = 1; c <= boardSize; c++)
                {
                        val = value[r][c];
                        
                        if (val == -1)
                        {
                                i = r;
                                j = c;
                                break;
                        }
                }
                
                if (val == -1) break;
        }
                
}

bool board::isLegal(int i, int j, int s)
{
        int sqrNum = squareNumber(i, j);
        
        bool row = c_rows[i][s];
        bool col = c_cols[j][s];
        bool sqr = c_sqrs[sqrNum][s];
        
        return (!(row || col || sqr));
        
}

void board::solve(long long int& recursiveCalls)
{
        recursiveCalls++;
        
        if (isSolved())
        {
                print();
                return;
        }
        else
        {       int i, j;
                findMostConstrainedCell(i, j);
                for (int s = 1; s <= boardSize; s++)
                {
                        if (isLegal(i,j,s))
                        {
                                setCell(i, j, s);
                                solve(recursiveCalls);
                                if (!isSolved())
                                {
                                        resetCell(i, j);
                                }
                        }
                }
        }
}

void board::findMostConstrainedCell(int& i, int& j)
{
        int maximum = 0;
        int sqrNum;
        int count_row, count_col, count_sqr;
        int curr_max;
        int val;
        
        for (int r = 1; r <= boardSize; r++)
        {
                for (int c = 1; c <= boardSize; c++)
                {
                        val = value[r][c];
                        
                        if (val == -1)
                        {
                                sqrNum = squareNumber(r, c);
                        
                                for (int s = 1; s <= boardSize; s++)
                                {
                                        count_row = count_if(c_rows[r].begin(), c_rows[r].end(), isTrue);
                                        count_col = count_if(c_cols[c].begin(), c_cols[c].end(), isTrue);
                                        count_sqr = count_if(c_sqrs[sqrNum].begin(), c_sqrs[sqrNum].end(), isTrue);
                                
                                        curr_max = count_row + count_col + count_sqr;
                                
                                        if (curr_max > maximum)
                                        {
                                                i = r;
                                                j = c;
                                                maximum = curr_max;
                                        }
                                }
                        }
                }
        }
}
