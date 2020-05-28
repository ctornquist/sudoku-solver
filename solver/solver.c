/* 
 * solver.c
 * 
 * Program to read an unsolved sodoku puzzle in from stdin and print the solved puzzle. 
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
#include "../common/functions.h"
#include "../libcs50/file.h"

int main(int argc, char **argv) {

    // load the board into a list
    int *list = getBoard();

    // solve the board
    bool solved = solve(list);

    // print the board
    if (solved) {
        // solved, print the board
        for (int i=0; i<81; i++){
            printf("%d ", list[i]);
            if ((i+1)%9 == 0) {
                printf("\n");
            }
        }
    }
    else {
        // not solvable
        printf("board cannot be solved\n");
    }

    free(list);

    return 0;
}
