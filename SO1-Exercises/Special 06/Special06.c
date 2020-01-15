/*
Author	    : Myungjun Kim
Contents    : Special exercise 06 - Determine the divisors and greatest common divisors of integers
*/

#define _CRT_SECURE_NO_DEPRECATE	// Else MSVC++ prevents using functions with potential buffer overflow
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes (provided by examiner) */
void sortDescending(int *a, int *b); // Sorts two integer values in descending order; a >= b.
int greatestCommonDivisor(int, int); // Returns the gcd of two integer variables m and n.
int getNumberOfDivisors(int m);		 // Returns the number of devisors (e.g. 5 for m = 18) of a natural number m.
int* newArrayOfDivisors(int m);		 /* Allocates and returns an integer array containing all divisors
										(e.g., 1, 2, 3, 6, 9, 18 for m = 18) of a natural number m.
										The allocated memory must have the correct size.
										The divisors must be sorted in ascending order. */
void clearBuffer(void);

/*
Expected output
Enter two positive integer numbers (comma-separated): 12 eighteen
Invalid input. Retry: 12 and 18
Invalid input. Retry: 12,18
Divisors of 12: 1 2 3 4 6
Greatest common devisor: gcd(12, 18) = 6
*/

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

	divisorArray = newArrayOfDivisors(inputOne); // Allocate an array containing the divisors of the first number entered by the user.

	// Print the divisors of the first number entered by the user to the console.
	numberOfDivisors = getNumberOfDivisors(inputOne);
	printf("Divisors of %d: ", inputOne);
	for (int i = 0; i < numberOfDivisors; i++)
		printf("%-2d", divisorArray[i]);

	// Prints the greatest common divisor of the numbers entered by the user to the console.
	//printf("Greatest common divisor: gcd(%d, %d) = ", inputOne, inputTwo, greatestCommonDivisor(inputOne, inputTwo));

	free(divisorArray); // Ensure that no memory leaks exist when the program terminates.
}

void sortDescending(int *a, int *b) // Sorts two integer values in descending order; a >= b.
{
	int temp;

	if (b > a)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

int greatestCommonDivisor(int m, int n) // Returns the gcd of two integer variables m and n.
{
	/*
	Greatest Common Divisor
	1. Use the function sortDescending() so that m contains the larger of the two numbers m and n(i.e., m >= n).
	2. Calculate the remainder r of the division m / n.
	3. Return the smaller number n, if the remainder r is 0.
	4. Else repeat steps 1 to 3 with the values of the smaller number n and the remainder r.
	*/

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