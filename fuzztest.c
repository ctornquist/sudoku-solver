/* 
 * fuzztest.c
 * 
 * Program to test creating and solving capabilities of our sudoku module. 
 *
 * CS50 - May 2020
 * Tornquist, Palmer, Wagner and Krivickas
 *
 */

#define _GNU_SOURCE 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <functions.h>
#include <stdbool.h>


int main(int argc, char **argv){
    if (argc != 2){
        fprintf(stderr, "Too many arguments\n");
    }

    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++){
        int *list = create_board();
        int *solution_list = malloc(81*sizeof(int));
        int num = 0;
        if (list != NULL) {
            printf("Randomly generated board with zeros: \n");
            print_board(list);

            int solved = solve(list, solution_list, num);
            if (solved != 0){
                printf("Solved board: \n");
                print_board(list);
            }
            else {
                fprintf(stdout, "Board not solveable\n");
            }
            printf("\n");
        }
    }


    return 0;
}
