# Sudoku Design Spec
A Sudoku puzzle is a 9x9 grid of cells, furhter divided into 9 3x3 grids.  Numbers 1-9 are placed in empty cells such that each number:

1. Only once in every row
2. Only once in every column
3. Only once in every 3x3 squared region

Sudoku `creator` module creates a 9x9 puzzle with 40 numbers missing such that the puzzle will have a unique solution.  The `solver` module finds a solution of a given puzzle, according to the rules above. The `sudoku` module runs the `creator` followed by the `solver`.


### User Interface
Sudoku's only interface with the user is on the command-line, and there is exactly one command-line for creating and another for solving.

* `./sudoku create` to create a random Suduko puzzle
* `./sudoku solve` to solve a given Sudoku puzzle


### Inputs and Outputs
*Creator*

* Input: No input
* Output: Creator prints a randomized Sudoku board with at least 40 missing numbers that has a unique solution.

*Solver*

* Input: The puzzle board is read from stdin in the form of 81 numbers (entered in lines of 9 at a time, or piped in). Blank spaces in the puzzle are indicated by 0s as placeholders
* Output: If the puzzle is solveable, solver will print the solved puzzle.


### Functional decomposition into modules
We anticipate the following modules or functions:

1. *main*, which validates arguments and calls appropriate `creator` or `solver` module
2. `solver`, which solves an incomplete board using backtracking
3. `creator` which creates a random board using `solver` then removes 40 numbers while preserving a unique solution


### Pseudo code for logic/algorithm flow
*Creator*

1. Generate solved puzzle

    2. Start with an empty board
    
    3. Choose a random array index from 1-81 and put in a random number from 1-9
    
    4. Call `solver` to fill the rest of the board
    
5. Remove 40 zeros preserving uniqueness of solution

    6. While zero-counter is less than 40
    
        7. Remove number at random cell and pass to solver
	
            8. If solver returns non-unique solution
	    
	            9. Replace cell with original number
		    
                10. Increase zero-counter by 1


*Solver*

1. read the data from stdin and initialize the array

2. solve(list)

	3. for each index 0-80
	
		4. if that index is 0
		
			5. for numbers 1-9
			
				6. if that number is valid (doesn't exist in row, column or box)
				
					7. add it to the list at the current index
					
					8. if solve(list)
					
						9. return true
						
					10. else
					
						11. set that index back to 0
						
			12. return false if looped through 1-9 and no number works
			
	13. if you've looped through each number and have no zeros, return true
	
14. if the puzzle is solvable, print it out




### Dataflow through modules
Sudoku: 

*  *Main*, which validates arguments and calls `creator` or `solver`

Creator:

* *create_board*, which creates a randomly solved board using *solve* and inserts 40 zeros using *isValid*
* *copy_list*, which copies all the elements of a list into another list, without copying the list pointers

Solver:

* *getBoard*, which loads the puzzle into an array from stdin
* *solve*, which solves provided Sudoku board
* *isValid*, check if given number does not already exist in row, column, or 3x3 grid
* *print_board*, prints the board.


### Testing plan

* *Integration Testing*: Assemble Sudoku and test as a whole using `testing.sh`
* Test the program with invalid command line arguments to ensure that validation of parameters in command-line works correctly.
* Unit tests for each function, testing the range of valid inputs
* Fuzztesting using *creator* module 