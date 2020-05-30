# sudoku_solver

### Usage
A sudoku puzzle has the numbers 1-9 in each column, row and 3x3 box such that they each only appear once. This module can both create sudoku puzzles and solve them. It is broken up into three directories: creator, which creates the sudoku boards, solver, which solves them if possible, and a common directory which contains helper functions used by both. 

### Assumptions
Solver does not error check what is read from stdin except to ensure there are 81 numbers. It does not check if those numbers are 0-9, and it assumes the user places 0s where there should be blanks in the board. 

//CREATOR ASSUMPTIONS HERE


### Compilation
To build the solver and creator, run "make". To remove executables and test files, "make clean."