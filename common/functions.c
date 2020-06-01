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
#include <time.h>

int *getBoard(FILE *fp);
const int solve(int *list, int *solution_list, const int num);
bool isValid(int number, int index, int *list);


//*************** getBoard ***************//
/* Loads the puzzle into an array from stdin. Assumes that blank spaces in the sudoku puzzle are
 * filled in with zeros. Array is indexed from 0-80 with the first row 0-8, second row 9-17 and
 * so on.
 */
int *getBoard(FILE *fp){
    // initialize list
    int *list = malloc(sizeof(int)*81);
    
    int count = -1;
    
    // read line by line
    bool read = true;
    while(read) {
        // get the line
        char *entry;
        entry = freadlinep(fp);
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
    if (count != 80) {
        printf("warning: board does not have 81 numbers\n");
    }
    return list;
}

//*************** solve ***************//
/* User provides an array representing the sudoku board, function will update list to include the 
 * numbers it solves for, returning true if it's solveable. 
 * 
 * parameters:
 * list = the orginal board
 * solution_list = empty lists of length 81
 * num = 0
 */
const int solve(int *list, int *solution_list, const int num) {
    int curr_num = num;

    // iterate through the 81 indexes
    for (int i=0; i<81; i++){
        if (list[i] == 0) {                         // if there's a blank space
            for (int j=1; j < 10; j++) {            // for each possible number 1-9
                if (isValid(j, i, list)) {          // check if it's valid
                    list[i] = j;                    // set that index to the valid number

                    //try to solve
                    const int temp_num = curr_num;
                    int result = solve(list, solution_list, temp_num);

                    //  if result == num
                    if (result == curr_num) {
                        // not solved, set back to 0 and try next number
                        list[i] = 0;
                    }
                    // if result == 1
                    else if (result == 1) {
                        // update number, and keep searching
                        curr_num = result;
                        list[i] = 0;
                    }
                    // if result == 2, return
                    else {
                        return 2;
                    }
                }
            }
            return curr_num;                           //looped through 1-9 and none work
        }
    }

    // if first solution, copy list into solution list
    if (num == 0) {
        for (int k = 0; k < 81; k++){
            solution_list[k] = list[k];
        }
    }
    // increment number of solutions and return
    const int number = num + 1;
    return number;                                    //looped through all indices and none are 0
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

/* Given an array that represents the board, print it out in 9x9 format
 */
void print_board(int *list){
    if (list != NULL){
        for (int i=0; i<81; i++){
            printf("%d ", list[i]);
            if ((i+1)%9 == 0) {
                printf("\n");
            }
        }
    }
}

/* Creates a board and returns the array that represents that board. The array will have
 * 81 numbers that are filled in with 0s as blanks. It is a uniquely solveable sudoku board. 
 */
int *create_board(){
    // Part [1]: generate filled board
    srand(time(NULL));

    // [a] start with empty board        
    int * list;
    list = (int*) calloc(81, sizeof(int)); // store puzzle as list of zeros

    // print board of zeros
    // fprintf(stdout, "\n****** print board of zeros ******\n");
    // for (int i=0; i<81; i++){
    //         printf("%d ", list[i]);
    //         if ((i+1)%9 == 0) {
    //             printf("\n");
    //         }
    // }

    // [b] insert random numbers in random cells if they are valid
    int i = 0;
    while (i < 5){
        int rand_num = (rand() % 9) + 1; // % 9 gives you rand betw 0-8
        //fprintf(stdout, "\nrand_num = %d\n", rand_num);
    
        int rand_cell = rand() % 81; // gives rand_cell betw 0-80
        //fprintf(stdout, "rand_cell = %d\n", rand_cell);


       if(isValid(rand_num, rand_cell, list)){
            list[rand_cell] = rand_num;
            i++;
        }   
    }


    // print board with random number
    // fprintf(stdout, "\n****** print board with random number ******\n");
    // print_board(list);


    // [c] use backtracking solver to fill the rest of the board
    // initialize empty list
    int * solution_list;
    solution_list = (int*) calloc(81, sizeof(int)); // store puzzle as list of zeros
    int num = 0;
    solve(list, solution_list, num);

    // print the board
    // fprintf(stdout, "\n****** print randomly solved board ******\n");
    // print_board(list);
        

    // Part [2]: generate a unique solvable puzzle with 40 zeros
        
    // [a] while counter < 40 (insert 40 zeros)
    int count_zero = 0;
    while(count_zero < 40){
            
        // go to random cell and count # of valid possible entries 1-9
        int rand_cell = rand() % 81;                // gives rand_cell betw 0-80
        //int rand_cell = index;

        if (list[rand_cell] != 0){
            int previous = list[rand_cell];
            list[rand_cell] = 0;
            //fprintf(stdout, " ~ list[rand_cell] != 0 ~\n");
                
            int * solution_list;
            solution_list = (int*) calloc(81, sizeof(int)); // initialize empty solution list
            int num = 0;
            int return_val;
            
            // if solve returns != 1 we put previous back, else leave 0 and increment count_zero
            if ((return_val = solve(list, solution_list, num)) != 1){
                list[rand_cell] = previous;
            } else {
                count_zero++;
            }
            

            //fprintf(stdout, "~ count_valid = %d ~\n", count_valid);

        }

    }

    // fprintf(stdout, "\n****** print finished board ******\n");
    return list;

}