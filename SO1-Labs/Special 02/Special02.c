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

	printf("Enter three integers formatted x,y,z: ");

	while (1)
	{
		if (scanf("%d,%d,%d", &intArray[0], &intArray[1], &intArray[2]) == 3 && getchar() == '\n')
			break;

		printf("Invalid input. Retry: ");
		clearKeyboardBuffer();
	}

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