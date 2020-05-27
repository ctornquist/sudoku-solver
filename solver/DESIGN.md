# Project - Sudoku Solver

### Inputs and Output
Inputs: The puzzle board is read from stdin in the form of 81 numbers (entered in lines of 9 at a time, or piped in). Blank spaces in the puzzle are indicated by 0s as placeholders.

Output: If the puzzle is solveable, solver will print the solved puzzle. 

### Modules
Two modules:
1. isValid, which checks whether a given number is a valid option given the other numbers in its row, column and box
2. solve, which updates the given array to include the solved numbers

### Pseudo Code
1. read the data from stdin and initialize the array
2. solve(list)
    * for each index 0-80
        *  if that index is 0
            * for numbers 1-9
                * if that number is valid (doesn't exist in row, column or box)
                    * add it to the list at the current index
                    * if solve(list)
                        * return true
                    * else
                        * set that index back to 0
            * return false if looped through 1-9 and no number works
    * if you've looped through each number and have no zeros, return true
3. if the puzzle is solvable, print it out


### Major Data Structures
The only data structure used is an array of integers that represents the puzzle board. 