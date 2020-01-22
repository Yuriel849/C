/*
Author	    : Myungjun Kim
Contents    : Special exercise 08 - Find and print all prime numbers in a given interval.
*/

#define _CRT_SECURE_NO_DEPRECATE	// Else MSVC++ prevents using functions with potential buffer overflow
#include <stdio.h>
#include <stdlib.h>

enum boolean { FALSE, TRUE };

/* Function prototypes */
int isEven(int);
enum boolean isPrimeNumber(int);
void clearBuffer(void);

int main(void)
{
	int input = 0, counter = 0;

	printf("Enter maximum number to test: "); // Users are asked to enter a positive integer number.
	while (1) // While the user input is not valid, users are asked to retry.
	{
		if (scanf("%d", &input) == 1 && input > 0 && getchar() == '\n')
			break;
		
		printf("Invalid input, must be positive integer. Retry: ");
		clearBuffer(); // The keyboard line buffer is emptied after each user input.
	}

	printf("Prime numbers in [1, %d]:\n", input);
	for (int iteration = 1; iteration <= input; iteration++)
	{
		if (isPrimeNumber(iteration))
		{
			printf("%4d ", iteration); // The numbers are aligned to the right in each column.
			counter++;
			
			if (counter % 10 == 0) // The prime numbers are printed in rows of 10 numbers each.
				printf("\n");
		}

	}
	printf("\nThere are %d prime numbers in [1, %d]", counter, input); // The number of prime numbers within the range is printed to the console.
}

int isEven(int a)
{
	return (a % 2 == 0) ? TRUE : FALSE;
}

enum boolean isPrimeNumber(int k)
{
	enum boolean result = TRUE;

	if (k <= 1 || (k >= 4 && isEven(k)))
		result = FALSE;

	for (int m = 3; m < k / 2.0; m += 2)
		if (k % m == 0)
			result = FALSE;

	return result;
}

void clearBuffer(void)
{
	while (getchar() != '\n')
		continue;
}