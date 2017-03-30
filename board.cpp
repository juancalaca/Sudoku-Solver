#include "board.h"

board::board(int sqSz) : sqSize(sqSz)
{
        boardSize = sqSize * sqSize;
        value.resize(boardSize + 1, boardSize + 1);
        c_rows.resize(boardSize + 1);
        c_cols.resize(boardSize + 1);
        c_sqrs.resize(boardSize + 1);
        
        for (int i = 1; i <= boardSize; i++)
        {
                c_rows[i].resize(boardSize + 1);
                c_cols[i].resize(boardSize + 1);
                c_sqrs[i].resize(boardSize + 1);
        }
}

void board::clear()
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
		{
			c_rows[i][j] = false;
			c_cols[i][j] = false;
			c_sqrs[i][j] = false;
		}
	}
}

void board::initialize(ifstream &fin)
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
{
        if (i < 1 || i > boardSize || j < 1 || j > boardSize)
                throw rangeError("bad value in isBlank");
        
        return (getCell(i,j) == -1);
}

int board::getCell(int i, int j) const
{
        if (i >= 1 && i <= boardSize && j >= 1 && j <= boardSize)
                return value[i][j];
        else
                throw rangeError("bad value in getCell");
}

void board::setCell(int i, int j, int val)
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
{
        //cout << boolalpha;
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
        // Note that (int) i/SquareSize and (int) j/SquareSize are the x-y
        // coordinates of the square that i,j is in.
        
        return sqSize * ((i-1)/sqSize) + (j-1)/sqSize + 1;
}

bool board::isSolved() const
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

/*void board::place(int i, int j, int val)
{
        if (i >= 1 && i <= boardSize && j >= 1 && j <= boardSize)
                value[i][j] = val;
        else
                throw rangeError("bad value in place");

        int sqrNum = squareNumber(i, j);
        c_rows[i][val] = true;
        c_cols[j][val] = true;
        c_sqrs[sqrNum][val] = true;
}*/

void board::resetCell(int i, int j)
{
        int val = value[i][j];
        
        if (i >= 1 && i <= boardSize && j >= 1 && j <= boardSize)
                value[i][j] = -1;
        else
                throw rangeError("bad value in remove");
        
        int sqrNum = squareNumber(i, j);
        c_rows[i][val] = false;
        c_cols[j][val] = false;
        c_sqrs[sqrNum][val] = false;

}
