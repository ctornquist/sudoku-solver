/* 
 * creator.c
 * 
 * Program to generate a uniquely solvable sudoku puzzle. Prints the puzzle to stdout. 
 *
 * CS50 - May 2020
 * Tornquist, Palmer, Wagner and Krivickas
 *
 */

#define _GNU_SOURCE 
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include "../common/functions.h"
#include "../libcs50/file.h"


int main(int argc, char **argv) {

    int *list = create_board();

    // print the board
    if (list != NULL){
        print_board(list);
    }
    
    return 0;
}