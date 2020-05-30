# Sudoku Project, May 2020


### Unit Testing
First, we ensured each of our individual modules were correct by creating unit tests. To test getBoard(), we fed it board with too few and too many numbers, as well as checked whether it could read from stdin (or another file pointer) properly. We tested isValid() by feeding it duplicate numbers in the same row, column and box, and ensured it returned false each time. Finally we tested solve by giving it a board, and then checking each number with the answers to compare results. 

//CREATOR TESTING HERE

### Fuzz Testing
We wrote ```fuzztest.c``` which takes an integer as a command line argument, and creates and solves that number of boards. The idea is that if we test a large number of times, if there is somehting wrong with the program we will get an error. ```fuzztest.c``` makes it easy to test both programs a lot very quickly. 

