# Testing script for indexer.c
# Authors: Tornquist, Palmer, Wagner and Krivickas
# Date: May 2020
#
# usage: bash -v testing.sh

#####################################
### These tests should fail ###

# sudoku: 0 arguments
./sudoku

# sudoku: 2 arguments
./sudoku solve create

# sudoku: incorrect argument
./sudoku hello

######################################
### These tests should pass ####

# indextest memory leaks
valgrind ./sudoku create
./sudoku create | valgrind ./sudoku solve

# compare solver outputs to make sure ./sudoku create generates puzzle with unique solution
echo putting created puzzle into ~outfile~
./sudoku create > outfile
echo solving puzzle into ~solved1~
cat outfile | ./sudoku solve > solved1
echo solving puzzle into ~solved2~
cat outfile | ./sudoku solve > solved2
echo comparing ~solved1~ and ~solved2~
diff solved1 solved2
