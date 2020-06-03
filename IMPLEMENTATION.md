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
2. While 10 random numbers have not been placed
    * Choose a random cell from 0-80 and a random value 1-9
    * Call isValid to check that the number can be placed there
    * If isValid returns true
        * Insert that random value at that random cell
3. Call solve on the current board
4. While the number of zeros is less than 40
    * Go to a random cell from 0-80
    * If cell is not zero
        * Store previous value and current board before passing into solver
        * Passing current board into solver passing in an empty solution list
        * If solver does not return 1 (i.e. non-unique solution)
            * Copy stored board back in 
            * Set value at random cell to previous stored value
        * Else if solver returns 1 (i.e. unique solution)
            * Copy stored board back in
            * Set value at random cell to zero
            * Increase number of zeros placed


### Data Structures
The only major data structure is an array of integers used to represent the board. 

### Error Handling
Exit Codes for sudoku.c:
* 1: Invalid number of arguments
* 2: Error allocating memory for storing command as a variable
* 3: Invalid command line: Must be either './sudoku create' or './sudoku solve'

There are no command line args here, and solver assumes that the board was typed in or piped in correctly. 
