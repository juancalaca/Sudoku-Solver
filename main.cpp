#include <iostream>

#include "board.h"
#include <fstream>
#include <iostream>

using namespace std;



int main()
{
        board b1(3);
        ifstream fin;
        
        while (true)
        {
                string fileName;
                cout << "Please enter full path for Sudoku Board file:" << endl;
                cin >> fileName;
                fin.open(fileName.c_str());
                if (fin) // file was succesfully opened
                        break;
                else // 
                        cout << "Error: file couldn't be opened: try again" << endl;
        }

        while (fin && fin.peek() != 'Z')
        {
                b1.initialize(fin);
                b1.print();
                b1.printConflicts();
                cout << "Is the board solved? " << boolalpha << b1.isSolved() << endl;
        }
        
        fin.close();
}
