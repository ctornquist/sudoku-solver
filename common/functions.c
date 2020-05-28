/* 
 * solver.c
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
#include "../libcs50/file.h"

int *getBoard();
bool solve(int *list);
bool isValid(int number, int index, int *list);


//*************** getBoard ***************//
/* Loads the puzzle into an array from stdin. Assumes that blank spaces in the sudoku puzzle are
 * filled in with zeros. Array is indexed from 0-80 with the first row 0-8, second row 9-17 and
 * so on.
 */
int *getBoard(){
    // initialize list
    int *list = malloc(sizeof(int)*81);
    
    int count = -1;
    
    // read line by line
    bool read = true;
    while(read) {
        // get the line
        char *entry;
        entry = freadlinep(stdin);
        if (entry == NULL){
            break;
        }
        char *str = malloc((strlen(entry)+1)*sizeof(char));
        strcpy(str, entry);

        // get first number
        char *num = NULL;
        num = strtok(str," "); // deliminate on space
        
        // iterate through the numbers
        while (num != NULL){
            count = count + 1;

            // add to list
            int number = atoi(num);
            list[count] = number;

            // get next number
            num = strtok(NULL, " \t");
        }

        free(entry);
        free(str);
    }
    return list;
}

//*************** solve ***************//
/* User provides an array representing the sudoku board, function will update list to include the 
 * numbers it solves for, returning true if it's solveable. 
 */
bool solve(int *list) {
    // iterate through the 81 indexes
    for (int i=0; i<81; i++){
        if (list[i] == 0) {                         // if there's a blank space
            for (int j=1; j < 10; j++) {            // for each possible number 1-9
                if (isValid(j, i, list)) {          // check if it's valid
                    list[i] = j;                    // set that index to the valid number

                    //try to solve
                    if (solve(list)) {
                        // solved
                        return true;
                    }
                    else {
                        // not solved, set back to 0 and try next number
                        list[i] = 0;
                    }
                }
            }
            return false;                           //looped through 1-9 and none work
        }
    }
    return true;                                    //looped through all indices and none are 0
}


//*************** isValid ***************//
/* Checks if the number given is valid, ie does not exist in the row, column, or box. 
 * 
 * User provides the number to check, the index in which it occurs in the array (sudoku puzzle) 
 * and the array that represents the puzzle itself. 
 */
bool isValid(int number, int index, int *list) {
    // indexes: 0-80
    // rows: 0-8
    // columns: 0-8
    // boxes: 0-2 (the 3x3 boxes in each puzzle)

    // check row
    // the first index in that row is the index/9
    int start = 9 * (index / 9);
    for (int c = start; c < start+9; c++) {
        if (list[c] == number) {
            return false;
        }
    }

    // check column
    // the column number is the index mod 9
    for (int i = (index % 9); i<81; i +=9) {
        if (list[i] == number) {
            return false;
        }
    }

    // check box
    int row_num = index/9;
    int col_num = index % 9;

    int box_row_num = row_num / 3;
    int box_col_num = col_num / 3;

    // we want get the first index in the box (top left)
    int box_index = (box_row_num * 9 * 3) + (box_col_num * 3);

    for (int i=box_index; i<box_index + 19; i += 9) {
        for (int j=0; j<3; j++){
            if (list[i+j] == number) {
                return false;
            }
        }
    }
    return true;
}
