#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <limits.h>
#include <math.h>

int FP_main()
{
	double a = 123456.7788;

	printf("%f\n", a);
	printf("%e\n", a); // Prints double in scientific notation

	getchar();
	return 0;
}