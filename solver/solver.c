/* 
 * solver - 
 *
 * CS50 - May 2020
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
#include "../libcs50/hashtable.h"
#include "../libcs50/file.h"

int *getBoard();
bool solve(int *list);


int main(int argc, char **argv) {

    // load the board into a list
    int *list = getBoard();

    // solve the board
    bool solved = solve(list);

    if (solve) {
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

// loads the board from stdin to a list
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




// bool solve(hashtable_t *board) {

//     // iterate through the 81 indexes
//     for (int i=0; i<82; i++){



//     }




// }

