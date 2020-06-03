# Sudoku Graphics

*NOTE*: Before running this graphics program, run the following command line from the top level directory:
`cp -r ./libcs50/ ./graphics/libcs50`

### Command Line
`cat graphicsIn.txt | ./sudoku solve > graphicsOut`

### Procedure
Compile `sudoku.c` with `make` which will compile everything with the appropriate macros tags.  Then run the above command line.  Go into `graphicsOut` and copy everything into the lines after the sudoku board in `test_file.txt`.  Then run `animate_board.py`.  

### Compilation
To compile sudoku.c for graphics, simply run `make` from this *graphics* directory. To remove executables and test files, "make clean."
