#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*
	5 (25 Points)
     Write a C main program that plays the following simplification of
     Conway's game of life.

     The program reads 10 integers from the terminal.
     The first integer is called numGen short for number of
     generations.  Check that it is positive and abort the run if it is
     not.  The remaining 9 integers must each be 0 or 1 (check that
     they are 0 or 1 and abort if not).

     View these 9 binary values as a 3x3 matrix.  So if the numbers
     were 1 1 1 0 1 0 1 0 1 you view them as
     1 1 1
     0 1 0
     1 0 1

     This matrix is called generation 0.

     Each element of the matrix is called a cell.  A cell has
     neighbors on top, bottom, left, right, and diagonals.  The four
     corner cells (matrix elements 0,0 0,2 2,0 2,2) each have only
     three neighbor; whereas, the middle cell (element 1,1) has eight
     neighbors.

     Generation 1 is calculated from generation 0 as follows.  First,
     for each cell in generation 0, count how many of its neighbors
     are 1.  If that count gives 2 or 3, the cell is 1 in generation
     1.  If the count is neither 2 nor 3, the cell is 0 in generation
     1.

     Repeat this process to produce all 9 values in generation 1.

     Then, using the generation 1 matrix, calculate the generation 2
     matrix using the same procedure.

     Stop when you reach generation numGen and print the resulting
     3 by 3 matrix on the screen.	
*/
int getint() {
    int value;
    if (scanf("%d", &value) != 1)
        exit(EXIT_FAILURE);
    else
        return value;
}

int main() {
    int a[9];
    int numGens, c;
    for (int i=0; i < 10; i++) {
        if (i == 0) {
            c = getint();
            if (c < 1)
                exit(EXIT_FAILURE);
            else
                numGens = c;
        } else {
            c = getint();
            if (c != 1 && c != 0)
                exit(EXIT_FAILURE);
            else
                a[i-1] = c;
        } 
    }
    int b[3][3];
    int new_generation[3][3];
    int numGensCompleted = 0; 

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            b[i][j] = a[(3 * i) + j];
        }
    }

    while (numGensCompleted < numGens) {
        int neighbors_that_are_1 = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                //up
                if (i > 0) {
                    if (b[i-1][j] == 1) {
                        neighbors_that_are_1 += 1;
                    }
                }
                //down
                if (i < 2) { 
                    if (b[i+1][j] == 1) {
                        neighbors_that_are_1 += 1;
                    }
                }
                //left
                if (j > 0) {
                    if (b[i][j-1] == 1) {
                        neighbors_that_are_1 += 1;
                    }
                }
                //right
                if (j < 2) { 
                    if (b[i][j+1] == 1) {
                        neighbors_that_are_1 += 1;
                    }
                }
                //diagonal down-right
                if ((i == 0 || i == 1) && (j == 0 || j == 1)) {
                    if (b[i+1][j+1] == 1) {
                        neighbors_that_are_1 += 1;
                    }
                }
                //diagonal up-right
                if ((i == 1 || i == 2) && (j == 0 || j == 1)) {
                    if (b[i-1][j+1] == 1) {
                        neighbors_that_are_1 += 1;
                    }
                }
                //diagonal down-left
                if ((i == 0 || i == 1) && (j == 1 || j == 2)) {
                    if (b[i+1][j-1] == 1) {
                        neighbors_that_are_1 += 1;
                    }
                }
                //diagonal up-left
                if ((i == 1 || i == 2) && (j == 1 || j == 2)) {
                    if (b[i-1][j-1] == 1) {
                        neighbors_that_are_1 += 1;
                    }
                }
                if (neighbors_that_are_1 == 2  || neighbors_that_are_1 == 3)
                    new_generation[i][j] = 1;
                else new_generation[i][j] = 0;
                
                neighbors_that_are_1 = 0;
            }
        }
        numGensCompleted += 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                b[i][j] = new_generation[i][j];
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}