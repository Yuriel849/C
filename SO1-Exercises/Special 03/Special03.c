/*
Author	    : Myungjun Kim
Contents    : Special exercise 03 - Print an 
*/

/* Include files */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void printArray(int a[], int size);  // Prints the elements of an int array to the console
int* cloneArray(int a[], int size);  // Create and return a copy of an existing int array, which is passed to the function as argument
void swap(int *a, int *b);			 // Swaps (exchange) the values of two int variables passed to the function as parameters
void invertArray(int a[], int size); // Reverses the order of values stored in an int array.

int main(void)
{
	// Declare an int array of size 9 and initialize its values in ascending order 1, 2, �, 9.
	int size, array[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *clone;

	// Define a variable which stores the number of elements in the array.
	size = sizeof array / sizeof array[0];

	// Print the array to the console using printArray().
	printf("Input   : ");
	printArray(array, size);

	// Create a clone using cloneArray() and print it to the console.
	clone = cloneArray(array, size);
	printArray(clone, size);

	// For the cloned array, invert the order of the elements using invertArray() and print the array to the console.
	invertArray(clone, size);
	printArray(clone, size);

	// Ensure that no memory leaks exist.
	free(clone);

	getchar();
	return 0;
}

void printArray(int a[], int size)  // Prints the elements of an int array to the console as a comma-separate list in brackets [ ]
{
	printf("[");
	for (int i = 0; i < size; i++)
	{
		printf("%d", a[i]);
		if (i != 8)
			printf(", ");
	}
	printf("]\n");
}

int* cloneArray(int a[], int size)  // Create and return a copy of an existing int array, which is passed to the function as argument
{
	int *clone = 0;

	if((clone = (int *)malloc(sizeof(int) * size)) == NULL)
		exit(EXIT_FAILURE);

	for (int i = 0; i < size; i++)
		clone[i] = a[i];

	return clone;
}

void swap(int *a, int *b)			// Swaps (exchange) the values of two int variables passed to the function as parameters
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void invertArray(int a[], int size) // Reverses the order of values stored in an int array.
{
	for (int i = 0; i < size / 2; i++)
		swap(&a[i], &a[size - 1 - i]); // The function invertArray() shall use swap() to exchange values.
}