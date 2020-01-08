/*
Author	    : Myungjun Kim
Contents    : Special exercise 01 - Implement a function to return the approximation of Euler's number.
*/

#define _CRT_SECURE_NO_DEPRECATE			// To use scanf() without warnings

#include <stdlib.h>
#include <stdio.h>

double eulerSeries(int);
void clearBuffer(void);

int main(void)
{
	int n = -10;

	printf("Maximum n to use : ");

	while ((scanf("%d", &n) != 1) || (n < 0))
	{
		printf("Input must be a non-negative integer. Retry : ");
		clearBuffer();
	}
	clearBuffer(); /* Even if successfully entered, input buffer must still be emptied */

	for (int iteration = 0; iteration <= n; iteration++)
		printf("n = %d : %f\n", iteration, eulerSeries(iteration));

	getchar();
	return 0;
}

double eulerSeries(int n)
{
	double sum = 0, product;

	for (int k = 0; k <= n; k++)
	{
		if (k == 0 || k == 1) /*0! == 1 && 1! == 1*/
			sum += 1;
		else
		{
			product = 1.0; /*Reinitialize product to 1 every time product is used*/
			for (int j = 1; j <= k; j++)
				product *= j;
			sum += 1 / product;
		}
	}

	return sum;
}

void clearBuffer(void)
{
	while (getchar() != '\n')
		continue;
}