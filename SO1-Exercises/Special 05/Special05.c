/*
Author	    : Myungjun Kim
Contents    : Special exercise 05 - Implement functionality for mathematical complex numbers z = x + jy with real part x and imaginary part y. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	double real;
	double imag;
} complex;

/* Function prototypes */
double absolute(complex z);				// Returns the absolute value |z| = sqrt(x^2 + y^2) of a complex number z.
complex add(complex a, complex b);		// Returns the sum a + b of two complex numbers a and b.
complex multiply(complex a, complex b); // Returns the product a * b of two complex numbers a and b.

int main(void)
{
	complex z1 = { 3., 4. };
	complex z2 = { 2.0, -1. };
	complex sum, product;

	/* Print complex numbers to the console */
	printf("Input data:\n");
	printf("z1 = %.1f %+.1fj\n", z1.real, z1.imag);
	printf("z2 = %.1f %+.1fj\n", z2.real, z2.imag);

	/* Absolute values */
	printf("\nAbsolute values:\n");
	printf("|z1| = %.3f\n", absolute(z1));
	printf("|z2| = %.3f\n", absolute(z2));

	/* Mathematical operations */
	printf("\nMathematical operations:\n");
	sum = add(z1, z2);
	product = multiply(z1, z2);
	printf("z1 + z2 = %.1f %+.1fj\n", sum.real, sum.imag);
	printf("z1 * z2 = %.1f %+.1fj\n", product.real, product.imag);

	getchar();
	return 0;
}

double absolute(complex z)				// Returns the absolute value |z| = sqrt(x^2 + y^2) of a complex number z.
{
	return sqrt((z.real * z.real) + (z.imag * z.imag));
}

complex add(complex a, complex b)		// Returns the sum a + b of two complex numbers a and b.
{
	complex result;
	
	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	
	return result;
}

complex multiply(complex a, complex b) // Returns the product a * b of two complex numbers a and b.
{
	complex result;

	result.real = (a.real * b.real) - (a.imag * b.imag);
	result.imag = (a.real * b.imag) + (a.imag * b.real);

	return result;
}