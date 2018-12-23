#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Lab 1, CSO 201 Gottlieb
//by Ivan Viro
//DUE OCT 11
//Part 3

/*
	3 (15 Points)
     Write a main program that reads characters from the terminal and
     writes characters on the screen.  Your program must use getchar()
     to read and putchar() to write.

     If the character read is not a letter, it is printed unchanged.

     If the character is an upper case letter, print the letter in
     lower case.

     If the character is a lower case letter, print the letter in
     upper case.	
*/

void main() {
	char c;
	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z')
			putchar((c-32));
		else if (c >= 'A' && c <= 'Z')
			putchar((c+32));
		else
			putchar(c);
    }
}