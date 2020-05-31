# Sudoku Implementation.md
## May 2020

### Detailed Psuedocode

getBoard:
1. intialize array of integers with 81 slots
2. while(true)
    * read a line in from stdin using freadlinep
    * if it's null, break
    * allocate a new string and copy what was read into it
    * use strtok on the copy using space as a delimiter to get the first number
    * while there are more numbers to be read
        * covert the char into an int
        * add it to the end of the list

isValid:
Notes: The indices are indexed 0-80, the columns and rows 0-8, and the boxes rows/columns 0-2. 
1. divide the index by 9 (integer division) and then multiply it by 9 to get the first index in the given number's row
    * start at that index, and keep adding 1 each time
        * if any of the numbers are the same as the given number, return false
2. take the index modulo 9 to get the first index in the given number's column 
    * start at that index, adding 9 each time
        * if the number at that index matches the given number, return false
3. get the row number (index/9) and column number (index % 9)
4. get the box row + column number by dividing each of the above by 3
5. the top left index in each box is (box_row * 27) + (box_col * 3)
6. starting at the top left index in each box, loop over each number in the box
    * if any are the same as the given number, return false
7. return true

solve: 
Notes: This is implemented as a recursive function, and is well described in DESIGN.md. 

create_board:
1. Generate board of 81 zeros
2. While four random numbers have not been placed
    * Choose a random cell from 0-80 and a random value 1-9
    * Call isValid to check that the number can be placed there
    * If isValid returns true
        * Insert that random value at that random cell
3. Call solve on the current board
4. Set current cell to 0
4. While the number of zeros is less than 40
    * Check that the current cell is not zero
    * If current cell if not zero
        * Loop over values 1-9
        * If only one the 9 values are valid at the current cell
            * Insert a zero at the current cell
            * Increment count_zeros by 1
            * Iterate to the next cell

Note: Research at MIT has shown that all possible sudoku puzzles with 16 cells originally filled never have a unique solution.  Puzzles with 17 cells filled are thought to be the lowest number by which unique solutions can be found.  Therefore, for creating a sudoku puzzle with a unique solution at optimal run time efficiency, the creator module can simply check for possible values at a given cell and put a zero there only if one value returns true from `isValid` instead of running `solve` after each change and checking for a different solved board.


### Data Structures
The only major data structure is an array of integers used to represent the board. 

### Error Handling
Exit Codes for sudoku.c:
* 1: Invalid number of arguments
* 2: Error allocating memory for storing command as a variable
* 3: Invalid command line: Must be either './sudoku create' or './sudoku solve'

There are no command line args here, and solver assumes that the board was typed in or piped in correctly. 
