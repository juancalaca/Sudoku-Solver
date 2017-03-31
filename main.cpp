//Project 4a
//seprod4a
//
//File: Main file
//the main file handles the process of "playing" the sudoko game
//it starts by reading in a file and continously solving the puzzle
//using the board class. Once there are no more puzzles to be solved
//the program exits.

#include <iostream>

#include "board.h"
#include <fstream>
#include <iostream>

using namespace std;



int main()
{		
		//initialize board b1 to have square size 3 (9x9 cells)
        board b1(3);
        ifstream fin;
        
        while (true)
        {
        		//loop for entering the name of the file to read from
                string fileName;
                cout << "Please enter full path for Sudoku Board file:" << endl;
                cin >> fileName;
                fin.open(fileName.c_str());
                if (fin) // file was succesfully opened
                        break;
                else //if file is not found, throw error and try again
                        cout << "Error: file couldn't be opened: try again" << endl;
        }

        while (fin && fin.peek() != 'Z')
        //read in the file and continuously check the next value to make sure it is not 'Z'
        //if the next character is a 'Z' then all of the boards have been solved
		{
                b1.initialize(fin);
                //initializes the board
                b1.print();
                //prints the board
                cout << endl;
                b1.printConflicts();
                //prints the conflicts
                cout << endl << "Is the board solved? " << boolalpha << b1.isSolved() << endl << endl;
                //prints whether or not the board has been solved
        }
        
        fin.close();
}
