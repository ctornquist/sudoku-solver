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

    // Part [1]: generate filled board
        srand(time(NULL));

        // [a] start with empty board
        int * list;
        list = (int*) calloc(81, sizeof(int)); // store puzzle as list of zeros

        // print board of zeros
        fprintf(stdout, "\n****** print board of zeros ******\n");
        for (int i=0; i<81; i++){
                printf("%d ", list[i]);
                if ((i+1)%9 == 0) {
                    printf("\n");
                }
            }

        // [b] insert random numbers in random cells if they are valid
        int i = 0;
        while (i < 5){
            int rand_num = (rand() % 9) + 1; // % 9 gives you rand betw 0-8
            fprintf(stdout, "\nrand_num = %d\n", rand_num);
        
            int rand_cell = rand() % 81; // gives rand_cell betw 0-80
            fprintf(stdout, "rand_cell = %d\n", rand_cell);


            if(isValid(rand_num, rand_cell, list)){
                list[rand_cell] = rand_num;
                i++;
            }   
        }


        // print board with random number
        fprintf(stdout, "\n****** print board with random number ******\n");
        for (int i=0; i<81; i++){
                printf("%d ", list[i]);
                if ((i+1)%9 == 0) {
                    printf("\n");
                }
            }

        // [c] use backtracking solver to fill the rest of the board
        bool solved = solve(list);

        // print the board
        if (solved) {
            // solved, print the board
            fprintf(stdout, "\n****** print randomly solved board ******\n");
            for (int i=0; i<81; i++){
                printf("%d ", list[i]);
                if ((i+1)%9 == 0) {
                    printf("\n");
                }
            }
        } else {
            // not solvable
            printf("board cannot be solved\n");
        }
        

    // Part [2]: generate a unique solvable puzzle with 40 zeros
        
        // [a] while counter < 40 (insert 40 zeros)
        int count_zero = 0;
        while( count_zero < 40){
            
            // go to random cell and count # of valid possible entries 1-9
            int rand_cell = rand() % 81;                // gives rand_cell betw 0-80
            
            if (list[rand_cell] != 0){
                int previous = list[rand_cell];
                list[rand_cell] = 0;
                //fprintf(stdout, " ~ list[rand_cell] != 0 ~\n");
                
                int count_valid = 0;
                for (int j=1; j < 10; j++) {            // for each possible number 1-9
                    //fprintf(stdout, " ~ j = %d ~\n", j);
                    if (isValid(j, rand_cell, list)) {          // check if it's valid
                        //fprintf(stdout, " ~ entered isValid if statement ~\n");
                        count_valid++;
                    }   
                }     

                //fprintf(stdout, "~ count_valid = %d ~\n", count_valid);

                // IF = 1, put zero in cell
                if(count_valid == 1){
                    //list[rand_cell] = 0;
                    count_zero++;                       // increment to next cell if zero is inserted
                    fprintf(stdout, " ~ count_zero = %d ~\n", count_zero);
                
                } else {

                    // put back previous cell value if we can't change to zero
                    list[rand_cell] = previous;
                }

            }
            
        }

    

        // print the board
        fprintf(stdout, "\n****** print board with zeros ******\n");
        for (int i=0; i<81; i++){
            printf("%d ", list[i]);
            if ((i+1)%9 == 0) {
                printf("\n");
            }
        }
    

    

    return 0;
}
