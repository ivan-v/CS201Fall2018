#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Lab 1, CSO 201 Gottlieb
//by Ivan Viro
//DUE OCT 11
//Part 2

/*2A (15 Points)
     Write the following C function

	int isPrime(int x) {
	   // If x<2 or x>1000, the input is erroneous and isPrime() returns -1.
	   // If 2<=x<=1000 and x is a prime number, isPrime() returns 1.
	   // If 2<=x<=1000 and x is not a prime number, isPrime() returns 0.
	}
*/

int isPrime(int x) {
	if (x < 2 || x > 1000) 
		return -1;
	else {
		int primeFound = 0;
  		for (int i = 2; i <= x / 2; i++) {
        	if ((x % i) == 0) {
            	primeFound = 1;
            	break;
        	}
    	}
		if (!primeFound)
			return 1;
		else 
			return 0;
	}
}

/*
	2B (10 Points)
     Write a main program that takes two command-line arguments,
     lo and hi.

     If lo > hi main() prints an appropriate error message and terminates.

     Assuming lo <= hi, main() calls isPrime(x) for each lo <= x <= hi.
     For each x, main() prints one line which states either
         x is invalid
         x is prime
         x is not prime
     (You don't print a literal x but instead the value of x).
*/

int main(int argc, char* argv[]) {
    int lo = atoi(argv[1]);
	int hi = atoi(argv[2]);
	if (lo > hi) {
		printf("lo is greater than hi");
		return -1;
	} else {
		for (int i = lo; i <= hi; i++) {
			if (isPrime(i) == -1)
				printf("%d is invalid \n", i);
			else if (isPrime(i) == 1)
				printf("%d is prime \n", i);
			else 
				printf("%d is not prime \n", i);
		}
	}
}