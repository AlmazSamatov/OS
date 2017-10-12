#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){

	int i = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;

	printf("size of int variable(in bytes): %lu, value of maximum integer: %d\n", sizeof(i), i);
	printf("size of float variable(in bytes): %lu, value of maximum float: %f\n", sizeof(f), f);
	printf("size of double variable(in bytes): %lu, value of maximum double: %f\n", sizeof(d), d);


	return 0;
}
