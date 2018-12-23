#include <stdio.h>
#include <math.h>

//Write two versions of mkRectangle, one that accepts two points, and one that accepts 4 real numbers

struct point {
  double x;
  double y;
};

struct rectangle {
  struct point ll;
  struct point ur;
};

struct rectangle mkRectangle(struct point a, struct point b) {
	struct rectangle rect1;
	rect1.ll = a;
	rect1.ur = b; 
	return rect1;
}

struct rectangle mkRectangle(double aa, double ab, double ba, double bb) {
	struct rectangle rect1;
	struct point ll = {aa, ab};
	rect1.ll = ll;
	struct point ur = {ba, bb};
	rect1.ur = ur;
	return rect1;
}

//How big is each version of sizeof(struct gameValType)?
//Assuming each int is 4 bytes, it would be 8 bytes.

//How big is sizeof employee?
//32, since padding is required for each of the arrays that hold two ints and a char,
//which makes it a size of 9 bits rounded up to 16 (because it needs to be a multiple of 8)