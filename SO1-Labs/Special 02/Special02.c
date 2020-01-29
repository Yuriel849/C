/*
Author	    : Myungjun Kim
Contents    : Special exercise 02 - Use recursive to sum three integers.
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

void clearKeyboardBuffer(void);
int arraySum(int *array, int index);

int main(void)
{
	int intArray[3];

	// Ask users to enter 3 comma-separated integer numbers.
	printf("Enter three integers formatted x,y,z: ");

	// Use a single call of scanf() to read all three comma-separated int values from the keyboard into an array of size 3.
	while (1) // Infinite loop => Only break when user input is valid.
	{
		// User input is only valid when three comma-separated int values are scanned and followed by 'enter'
		if (scanf("%d,%d,%d", &intArray[0], &intArray[1], &intArray[2]) == 3 && getchar() == '\n')
			break;

		printf("Invalid input. Retry: "); // While the user input is invalid, users are asked to retry.
		clearKeyboardBuffer(); // The keyboard input is emptied after every user input.
	}

	// For valid user input, getchar() was called so keyboard buffer is already empty.

	// Calculate the sum of all elements in the array and print the result to the console.
	printf("Sum = %d", arraySum(intArray, 3));

	getchar();
	return 0;
}

// Removes all characters from the keyboard buffer.
void clearKeyboardBuffer(void)
{
	while (getchar() != '\n')
		continue;
}

// Returns the sum of all elements contained in an int array, using recursive function calls.
int arraySum(int *array, int index)
{
	int result = array[--index];

	if (index > 0)
		result += arraySum(array, index);

	return result;
}