#include <stdio.h>

//Write a C funcion int odd (int x) that returns 1 if x is odd and returns 0 if x is even. Can you do it without an if statement?
int odd(int x) {
	return x % 2;
}

//Write rotate3(A,B,C) that sets A to the old value of B, sets B to old C, and C to old A.
//int data type assumed.
void rotate3(int A, int B, int C) {
	int temp1 = A, temp2 = B, temp3 = C;
	A = temp2;
	B = temp3;
	C = temp1;
}

//Write plusminus(x,y) that sets x to old x + old y and sets y to old x - old y.

void plusminus(int x, int y) {
	int old_x = x;
	x = (x + y);
	y = (old_x - y);

}