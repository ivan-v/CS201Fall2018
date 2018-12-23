#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Lab 1, CSO 201 Gottlieb
//by Ivan Viro
//DUE OCT 11
//Part 1

/*1 (15 points)
     Write a main program that has three command line arguments called
     start, end, and incr.  All three are integers.
     Your program prints a series of numbers
        start, start+incr, start+(2*incr), ..., end
     For example, if the three arguments are 2, 10, and 3, the values
     printed are 2, 5, 8, 10.
     Note from the example that the end value is printed even if it is
     not of the form start plus a multiple of incr.

     You may assume for problem 1 that the arguments are legal, i.e.,
     start<end and incr>0. 
 */

int main(int argc, char* argv[]) {
    int start = atoi(argv[1]);
	int end = atoi(argv[2]);
	int incr = atoi(argv[3]);
	for (int i = 0; start+(i*incr) < end; i++) {
		printf("%d, ", start+(i*incr));
	}
	printf("%d.\n", end);
}
