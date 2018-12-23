#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Lab 1, CSO 201 Gottlieb
//by Ivan Viro
//DUE OCT 11

int getint() {
    int value;
    if (scanf("%d", &value) != 1)
        exit(EXIT_FAILURE);
    else
        return value;
}

/*
	4A (10 Points)
     Write the following C function

	void sortInt(int n, int A[n]) {
	   // This routine sorts the array A.
	   // Since arrays are passed to functions as a pointers, you do not
	   // need the pointer trick we did in class for bad_swap in 6.2.
	}
*/

void sortInt(int n, int A[]) {
    int sorted = 1;
    for (int i = 0; i < n-1; i++) {
        if (A[i] > A[i+1])
            sorted = 0;
    }
    if (sorted)
        return;
    else
        for (int i=0; i < n; i++) {
            for (int j=0; j < n-1; j++) {
                if (A[j] > A[j+1]) {
                    int temp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = temp;
                }
            }
        }
    return;
}

/*
	4B (10 Points)
     Write a main program that does all the following.  I suggest,
     but do not require, that you use getint() from the notes and
     given on page 97 of the book.

     * Reads a positive integer N.
     * Checks that 0<N<100.  If N is not in that range, prints
         an error message and terminates.
     *  Assuming N is legal
         i.   Reads N more integers into an array.
     ii.  Prints the contents of the array, one number per line.
     iii. Calls your sort routine from part A.
     iv.  Prints the sorted array, one number per line.
*/

int main() {
    int arr[100];
    int arrSize = getint();
    if (!(0 < arrSize && arrSize < 100)) {
        fputs("error: N must be between 0 and 100, exclusive", stderr);
        return EXIT_FAILURE;
    }
    for (int i=0; i < arrSize; i++) {
        //fill the array while more ints are expected
        arr[i] = getint();
        }
    for (int i=0; i < arrSize; i++) {
        printf("%d \n", arr[i]);
    }
    sortInt(arrSize, arr);
    for (int i=0; i < arrSize; i++) {
        printf("%d \n", arr[i]);                
    }
    return 0;
}