# sudoku_solver

### Usage
To compile sudoku.c and build the solver and creator modules from the top level directory, run "make". To remove executables and test files, "make clean."

To create a board, run "./sudoku create". To solve, run "./sudouku solve" (must type a board into stdin). One can also pipe the output from create to solve to do both in one step, i.e. "./sudoku create | ./sudoku solve". 

### Overview
A sudoku puzzle has the numbers 1-9 in each column, row and 3x3 box such that they each only appear once. This module can both create sudoku puzzles and solve them. It uses zeros to indicate blank spaces in the board. It is broken up into three directories: creator, which creates the sudoku boards, solver, which solves them if possible, and a common directory which contains helper functions used by both. 

### Assumptions
Solver does not error check what is read from stdin except to ensure there are 81 numbers. It does not check if those numbers are 0-9, and it assumes the user places 0s where there should be blanks in the board. 
