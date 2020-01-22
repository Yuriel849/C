/*
Author	    : Myungjun Kim
Contents    : Special exercise 04 - Implement an application to calculate and print values 2^n
									with n being non-negative integer numbers in the range 0, 1, 2, ..., N.
*/

#define _CRT_SECURE_NO_DEPRECATE			// To use scanf() without warnings

#include <stdlib.h>
#include <stdio.h>

#define MAXIMUM 16 // Define an int constant containing the maximum allowed exponent N (e.g., 16).

void clearBuffer(void);

int main(void)
{
	int input = -10;
	
	// Ask users to enter n in the range from 0 to the maximum allowed exponent N.
	printf("Calculation of 2^n with n in [0,16]:\nEnter n: ");
	while (1)
	{
		// Use the scanf() function to read n from the keyboard.
		if (scanf("%d", &input) != 1)
		{
			clearBuffer();
			printf("Press any key to quit.");
			getchar();
			exit(EXIT_FAILURE);
		}

		clearBuffer();
		
		// While the user input is an invalid integer value, users are asked to retry.
		if (input < 0 || input > 16)
		{
			printf("Incorrect input: Not in [0,16]\nEnter n: ");
			continue;
		}

		// If user input is valid, print the value 2^n to the console.
		printf("%d^%d = %d\nEnter n: ", 2, input, 1 << input); // Calculate the value 2^n by bit operation(s).
	}

	return 0;
}

void clearBuffer(void)
{
	while (getchar() != '\n')
		continue;
}