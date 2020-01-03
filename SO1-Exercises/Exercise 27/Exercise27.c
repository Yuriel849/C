/* Author	   : Myungjun Kim
   Contents    : Exercise 27.
   Instructions: Write a function scalarProduct() that returns the scalar product < x1, x2 >= x1·x2 of two vectors.
 */

#include <stdio.h>
#include <stdlib.h>

int scalarProduct(double *firstVector, double *secondVector, int size);

int main(void)
{
	int size = 3;
	double firstVector[3] = { 1, 3, 5 }, secondVector[3] = { 2, 4, 6 };

	printf("The scalar product (== dot product) of the two vectors is %d\n", scalarProduct(firstVector, secondVector, size));

	getchar();
	return 0;
}

int scalarProduct(double *firstVector, double *secondVector, int size)
{
	int returnValue = 0;

	for (int i = 0; i < size; i++)
		returnValue += firstVector[i] * secondVector[i];

	return returnValue;
}