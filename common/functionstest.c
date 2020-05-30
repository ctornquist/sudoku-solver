// unit tests for functions.h

#define _GNU_SOURCE 
#include<stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>
#include "./functions.h"
#include "../libcs50/file.h"

// testboards:
// board1 -> valid board
// board2 -> board with <81 numbers
// board3 -> board with >81 numbers
// board4 -> board for testing isValid
// board5 -> unsolved board
// board6 -> the board5 solution

int main() {

    //***************** getBoard tests *****************//
    printf("\n");
    printf("getBoard tests:\n");

    // valid board
    printf("valid board test: ");
    FILE *fp = fopen("./testboards/board1", "r");
    int *board = getBoard(fp);
    fclose(fp);
    if (board == NULL) {
        printf("fail\n");
    }
    else {
        bool pass = true;
        for (int i = 0; i<81; i++){
            if (board[i] == 0 && pass == true){
                printf("fail\n");
                pass = false;
            }
        }
        if (pass) { printf("pass\n"); }
    }
    free(board);

    // board with too few numbers
    printf("too few numbers test: ");
    FILE *fp2 = fopen("./testboards/board2", "r");
    int *board2 = getBoard(fp2);
    fclose(fp2);
    free(board2);

    // board with too many numbers
    printf("too many numbers test: ");
    FILE *fp3 = fopen("./testboards/board3", "r");
    int *board3 = getBoard(fp3);
    fclose(fp3);
    free(board3);


    //***************** isValid tests *****************//
    printf("\n");
    printf("isValid tests: \n");
    FILE *fp4 = fopen("./testboards/board4", "r");
    int *board4 = getBoard(fp4);
    fclose(fp4);

    // isValid should return false:
    // test the column
    printf("column test: ");
    if (!isValid(2,1,board4)){
        printf("pass\n");
    } else {printf("fail\n");}

    // test the row
    printf("row test: ");
    if (!isValid(4,1,board4)){
        printf("pass\n");
    } else {printf("fail\n");}

    // test the sub-box
    printf("sub-box test: ");
    if (!isValid(3,1,board4)){
        printf("pass\n");
    } else {printf("fail\n");}


    // isValid should retrun true
    // pick a valid number
    printf("valid selection test: ");
    if (isValid(5,1,board4)){
        printf("pass\n");
    } else {printf("fail\n");}
    free(board4);


    //***************** solve test *****************//
    printf("\n");
    printf("solve tests: \n");

    // solve should return true
    FILE *fp5 = fopen("./testboards/board5", "r");
    int *board5 = getBoard(fp5);
    fclose(fp5);
    // get the solved board
    if (solve(board5)) {
        // get the answer
        FILE *fp6 = fopen("./testboards/board6", "r");
        int *board6 = getBoard(fp6);
        fclose(fp6);
        // compare solved solution to real solution
        bool pass = true;
        for (int i=0; i<81; i++) {
            if (board5[i] != board6[i]) {
                printf("fail\n");
                pass = false;
                break;
            }
        }
        if (pass) { printf("pass\n"); }
        free(board6);
    } else { printf("fail\n"); }
    free(board5);

    return 0;
}