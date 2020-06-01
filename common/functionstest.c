/* functionstest.c  May 2020
 * A collection of unit tests to ensure the correctness of the functions in functions.c. 
 * Tests the getBoard(), isValid() and solve() functions. 
 */

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
// board7 -> board with multiple solutions

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

    // test a board with only 1 solution:
    // get the board
    FILE *fp5 = fopen("./testboards/board5", "r");
    int *board5 = getBoard(fp5);
    fclose(fp5);

    // initialize the solution list
    int *solution_list = malloc(sizeof(int)*81);

    // intialize number of solutions
    const int num = 0;

    // solve
    const int result = solve(board5, solution_list, num);

    // get the solved board
    if (result == 1) {
        // get the answer
        FILE *fp6 = fopen("./testboards/board6", "r");
        int *board6 = getBoard(fp6);
        fclose(fp6);
        // compare solved solution to real solution
        bool pass = true;
        for (int i=0; i<81; i++) {
            if (solution_list[i] != board6[i]) {
                printf("fail\n");
                pass = false;
                break;
            }
        }
        if (pass) { printf("pass\n"); }
        free(board6);
    } else { printf("fail\n"); }

    free(board5);
    free(solution_list);


    // test a board with multiple solutions:
    // get the board
    FILE *fp7 = fopen("./testboards/board7", "r");
    int *board7 = getBoard(fp7);
    fclose(fp7);

    // initialize the solution list
    int *solution_list2 = malloc(sizeof(int)*81);

    // intialize number of solutions
    const int num2 = 0;

    // solve
    const int result2 = solve(board7, solution_list2, num2);

    // print_board(solution_list2);
    // printf("\n");
    // printf("%d\n", result2);

    if (result2 == 2) {
        printf("pass\n");
    }
    else {printf("fail\n");}

    free(board7);
    free(solution_list2);

    return 0;
}