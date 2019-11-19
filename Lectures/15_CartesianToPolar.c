#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <corecrt_math_defines.h>

void convertPolar(double, double, double*, double*);

int cP_main(void)
{
	double x = 2.0, y = 3.75;
	double r, phi;

	convertPolar(x, y, &r, &phi);

	printf("Cartesian: (x, y)   = (%.2f, %.2f)\n", x, y);
	printf("Polar    : (r, phi) = (%.2f, %.2f * pi)\n", r, phi / M_PI);

	getchar();
	return 0;
}

void convertPolar(double x, double y, double *r, double *phi)
{
	*r = sqrt(x * x + y * y);
	*phi = atan2(y, x);
}