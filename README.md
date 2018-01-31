# Sudoku Solver

This program solves Sudoku puzzles. The input to Sudoku is a 9x9 board that is subdivided
into 3x3 squares. Each cell is either blank or contains an integer from 1 to 9.
This program solves the board so that every blank cell is filled in with a digit from 1 to 9 such
that every digit appears exactly once in every row, column, and square. Sample sudoku boards are
provided to test the program. This program also counts how many times the function solve() is called
recursively to solve the puzzle. The goal was to minimize the number of recursive calls to succesfully 
solve each puzzle. It will print the empty sudoku board, the solved board, and the number of recursive calls done to fully solve the board. It will do so for every board, in the end it will print the total number of recursive calls and the average number of recursive calls.

## Compilation
Run makefile by running ``make`` and then running ``main`` executable file created. Please input the file path to the ``sudoku1-3.txt`` file to get the program started.
