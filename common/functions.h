/* 
 * functions.h
 * 
 * Functions used by the solver and creator 
 *
 * CS50 - May 2020
 * Tornquist, Palmer, Wagner and Krivickas
 *
 */

#define _GNU_SOURCE 
#include<stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>

//*************** getBoard ***************//
/* Loads the puzzle into an array from stdin and returns the array when complete. Assumes that 
 * blank spaces in the sudoku puzzle are filled in with zeros. Array is indexed from 0-80 with
 * the first row 0-8, second row 9-17 and so on.
 */
int *getBoard(FILE *fp);

//*************** solve ***************//
/* User provides an array representing the sudoku board, function will update list to include the 
 * numbers it solves for, returning true if it's solveable. 
 */
bool solve(int *list);

//*************** isValid ***************//
/* Checks if the number given is valid, ie does not exist in the row, column, or box. 
 * 
 * User provides the number to check, the index in which it occurs in the array (sudoku puzzle) 
 * and the array that represents the puzzle itself. 
 */
bool isValid(int number, int index, int *list);


/* Given an array that represents the board, print it out in 9x9 format
 * Ignores boards that are null
 */
void print_board(int *list);


/* Creates a board and returns the array that represents that board. The array will have
 * 81 numbers that are filled in with 0s as blanks. It is a uniquely solveable sudoku board. 
 */
int *create_board();