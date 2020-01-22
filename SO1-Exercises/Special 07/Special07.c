/*
Author	    : Myungjun Kim
Contents    : Special exercise 07 - Implement functionality for mathematical vectors a = (x, y)T with components x and y.
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 2

/* Function prototypes */
void printVector2D(const double a[DIM]);
double vectorLength(const double a[DIM]);
void scaleVector2D(double a[DIM], double k);
double vectorProduct2D(const double a1[DIM], const double a2[DIM]);

/* Main function */
int main(void)
{
	double a1[DIM] = { 3., 4. };
	double a2[DIM] = { -2., 6. };

	/* Print vectors to the console */
	printf("Vectors:\na1 = ");
	printVector2D(a1);
	printf("\na2 = ");
	printVector2D(a2);
	printf("\n\n");

	/* Vector length */
	printf("Vector length:\n||a1|| = %.1f\n\n", vectorLength(a1));

	/* Scale vector */
	scaleVector2D(a2, 0.5);
	printf("Scale a2 with 0.5:\na2 = ");
	printVector2D(a2);
	printf("\n\n");

	/* Vector product */
	printf("Vector product:\n<a1, a2> = %.1f\n\n", vectorProduct2D(a1, a2));

	getchar();
	return 0;
}

void printVector2D(const double a[DIM])
{
	printf("(%3.1f, %3.1f)", a[0], a[1]);
}

// Returns the length |a| = sqrt(x2 + y2) of a vector.
double vectorLength(const double a[DIM])
{
	return (a[0] * a[0]) + (a[1] * a[1]);
}

// Scales (i.e., multiplies) a vector a with a floating-point number k of type double.
void scaleVector2D(double a[DIM], double k)
{
	a[0] *= k;
	a[1] *= k;
}

// Calculates and returns the vector product <a1, a2> = x1 * x2 + y1 * y2 of two vectors a1 = (x1, y1)T and a2 = (x2, y2)T.
double vectorProduct2D(const double a1[DIM], const double a2[DIM])
{
	return (a1[0] * a2[0]) + (a1[1] * a2[1]);
}
