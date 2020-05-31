# Sudoku Project, May 2020


### Unit Testing

For effective unit testing, the team wrote all creator and solver functions into the ```functions.h``` library (found in common). Then wrote ```creator.c``` and ```solver.c``` for seperate unit testing before compiling the two components into one, with ```sudoku.c```. Finally, we tested ```sudoku.c``` with a bash script titled ```testing.sh``` and piped its output to ```testing.out```.

*A. Unit testing for the solver:*
First, we ensured each of our individual modules were correct by creating unit tests. To test getBoard(), we fed it board with too few and too many numbers, as well as checked whether it could read from stdin (or another file pointer) properly. We tested isValid() by feeding it duplicate numbers in the same row, column and box, and ensured it returned false each time. Finally we tested solve by giving it a board, and then checking each number with the answers to compare results. 

*B. Unit testing for the creator:*
The creator component relied heavily on solver modules, so after solver unit testing showed success the team only had create_board() left to test. Print statements within create_board() showed that the function successfully created a randomly filled board and subsequently added 40 zeros for a puzzle with a unique solution. The team tested for a unique solution during sudoku unit testing.

*C. Unit testing for sudoku (ie. creator + solver):*
```testing.sh``` handled sudoku testing. First, it ran several different cases of commandline input. Then, it tested for memeory leaks. And finally, it compared output for ./sudoku solve after running it twice to make sure both solutions matched. Output showed they did so create_board() successfully generates a uniquely solvable puzzle. Ie. ```diff solved1 solved2``` had no output so both solutions matched.

### Fuzz Testing
We wrote ```fuzztest.c``` which takes an integer as a command line argument, and creates and solves that number of boards. The idea is that if we test a large number of times, if there is somehting wrong with the program we will get an error. ```fuzztest.c``` makes it easy to test both programs a lot very quickly. 

