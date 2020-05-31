/* 
 * sudoku.c
 * 
 * Program to generate a uniquely solvable sudoku puzzle. Prints the puzzle to stdout. 
 *
 * CS50 - May 2020
 * Tornquist, Palmer, Wagner and Krivickas
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


int main(int argc, char *argv[]){

    // Check for correct number of parameters
    if (argc != 2) {
        fprintf(stderr, "Error: Invalid Number of Arguments\n");
        return 1;
    }

    // Store create or solve command as a variable
    char *command = malloc(strlen(argv[1]) * sizeof(char) + 1);
    if (command == NULL) {
        fprintf(stderr, "Error allocating memory for storing command as a variable\n");
        return 2;
    }

    strcpy(command, argv[1]);

    // Check if argument was "create"
    if (strcmp(command, "create") == 0) {
        // Generate board with unique solution with at least 40 zeros
        int *board = create_board();
 
        // Print generated sudoku board
        print_board(board);

        free(board);
    }

    // Check if argument was "solve"
    else if (strcmp(command, "solve") == 0) {
        // load the board into a list
        int *board = NULL;
        board = getBoard(stdin);

        // solve the board
        bool solved = solve(board);

        // print the board
        if (solved) {
            // solved, print the board
            print_board(board);
        }
        else {
            // not solvable
            printf("board cannot be solved\n");
        }

        free(board);
    }

    // Arguments was neither create nor solve
    else {
        fprintf(stderr, "Command line should be either './sudoku create' or './sudoku solve'\n");
        return 3;
    }


    // Free alloc'd memory
    free(command);    

    return 0;
}
