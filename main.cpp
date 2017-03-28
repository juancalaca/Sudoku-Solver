#include <iostream>

#include "board.h"
#include <fstream>
#include <iostream>

using namespace std;



int main()
{
        board b1(3);
        board b2(3);
        ifstream fin;
        while (true)
        {
                string fileName;
                cout << "Please enter file name for sudoku board" << endl;
                cin >> fileName;
                fin.open(fileName.c_str());
                if (fin)
                        break;
                else
                        cout << "Error: file couldn't be opened: try again" << endl;
        }

        while (fin && fin.peek() != 'Z')
        {
                b1.initialize(fin);
                b1.print();
                b1.printConflicts();
                /*b1.place(1, 2, 9);
                b1.print();
                b1.printConflicts();
                b1.remove(7,7);
                b1.print();
                b1.printConflicts();*/
                cout << "Is solved? " << b1.isSolved() << endl;
        }
        
        //cout << "Is solved? " << b1.isSolved() << endl;
}
