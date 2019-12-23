/* Author	   : Myungjun Kim
   Contents    : Exercise 22.
   Instructions: Write a function to calculate the mean value x of a vector x = (x1, x2, . . . , xN )T
 */

#include <stdio.h>
#include <stdlib.h>

int calculateMean(int *vector, int size);

int main(void)
{
	int x[7] = { 1, 3, 5, 7, 9, 11, 13 }; // mean is sum divided by number => here, mean is 7
	int result = 0;

	result = calculateMean(x, 7);

	printf("This is the mean vaue of the vector x : %d", result);

	getchar();
	return 0;
}

int calculateMean(int *vector, int size)
{
	int mean = 0;

	for (int i = 0; i < size; i++)
		mean += vector[i];

	mean /= size;

	return mean;
}