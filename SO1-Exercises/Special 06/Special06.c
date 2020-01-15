/*
Author	    : Myungjun Kim
Contents    : Special exercise 06 - Determine the divisors and greatest common divisors of integers
*/

#define _CRT_SECURE_NO_DEPRECATE	// Else MSVC++ prevents using functions with potential buffer overflow
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void clearBuffer(void);
void sortDescending(int *a, int *b); // Sorts two integer values in descending order; a >= b.
int greatestCommonDivisor(int, int); // Returns the gcd of two integer variables m and n.
int getNumberOfDivisors(int m);		 // Returns the number of devisors (e.g. 5 for m = 18) of a natural number m.
int* newArrayOfDivisors(int m);		 /* Allocates and returns an integer array containing all divisors of a natural number m.
										The allocated memory must have the correct size.
										The divisors must be sorted in ascending order. */

int main(void)
{
	int inputOne, inputTwo, numberOfDivisors;
	int *divisorArray;

	// Users are asked to enter two positive integer numbers.
	printf("Enter two positive integer numbers (comma-separate): ");

	// While the user input is not valid, users are asked to retry.
	while (scanf("%d,%d", &inputOne, &inputTwo) != 2)
	{
		clearBuffer(); // The keyboard line buffer is emptied after each user input.
		printf("Invalid input. Retry: ");
	}
	clearBuffer();

	// Print the divisors of the first number entered by the user to the console.
	divisorArray = newArrayOfDivisors(inputOne); // Allocate an array containing the divisors of the first number entered by the user.
	printf("Divisors of %d: ", inputOne);
	for (int i = 0; i < getNumberOfDivisors(inputOne); i++)
		printf("%-2d", divisorArray[i]);

	// Prints the greatest common divisor of the numbers entered by the user to the console.
	printf("\nGreatest common divisor: gcd(%d, %d) = %d", inputOne, inputTwo, greatestCommonDivisor(inputOne, inputTwo));

	free(divisorArray); // Ensure that no memory leaks exist when the program terminates.
}

void sortDescending(int *a, int *b) // Sorts two integer values in descending order; a >= b.
{
	int temp;

	if (*b > *a)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

int greatestCommonDivisor(int m, int n) // Returns the gcd of two integer variables m and n.
{
	int gcd = 0, r = 0;

	do // Calculate the greatest common divisor with the Euclidean algorithm
	{
		sortDescending(&m, &n);
	
		if ((r = m % n) == 0)
			gcd = n;
		else
		{
			m = n;
			n = r;
		}
	} while (r != 0);

	return gcd;
}

int getNumberOfDivisors(int m)		 // Returns the number of devisors (e.g. 5 for m = 18) of a natural number m.
{
	int counter = 0;

	for (int index = 1; index <= m; index++)
		if ((m % index) == 0)
			counter++;
	
	return counter;
}

int* newArrayOfDivisors(int m)		 // Allocates and returns an integer array containing all divisors of a natural number m.
{
	int *divisorArray;

	if((divisorArray = (int *)malloc(sizeof(int) * getNumberOfDivisors(m))) == NULL)
		exit(EXIT_FAILURE);

	for (int index = 1, counter = 0; index <= m; index++)
		if ((m % index) == 0)
			divisorArray[counter++] = index;

	return divisorArray;
}

void clearBuffer(void)
{
	while (getchar() != '\n')
		continue;
}