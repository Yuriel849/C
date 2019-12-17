/* Author	   : Myungjun Kim
   Contents    : Exercise 15.
   Instructions: Approximate the value of an infinite series, where k is incremented from 0 to infinity, and 2 to the power of -k is added to the sum.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main(void)
{
	int k = 1;
	double result = 1, oldSum = 0, sum = 1;

	while (1) // Run an infinite loop
	{
		oldSum = sum; // Save previous value of sum to compare with after calculating
		result *= 0.5; // Multiply the result of the previous loop's calculation by 1/2 (== 0.5)
		sum += result; // Add the result of this loop's calculation to the sum
		printf("-----------------------------------------\n");
		printf(" | k = %d, sum = %.20f | \n", k, sum);
		k++;

		if (oldSum == sum) // Break while loop if the value of the equation has been reached
			break;
	}

	printf("-----------------------------------------\n");
	printf("p == %.2f", sum);

	getchar();
	return 0;
}