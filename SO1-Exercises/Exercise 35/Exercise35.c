/* Author	   : Myungjun Kim
   Contents    : Exercise 35.
   Instructions: Write a function createRandomArray() that allocates an int array and initializes it with random numbers.
				 Users shall enter the array size as well as the minimum and maximum random value in the main() function.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

void createRandomArray(int *randomArray, int size, int minimum, int maximum);
void printArray(int *randomArray, int size);

int main(void)
{
	int size = 0, minimum = 0, maximum = 0;
	int **randomArray;

	printf("Please help us create an array of integers filled with random numbers.\nFirst, please choose the size of the array.\n");
	scanf("%d", &size);
	printf("Next, please choose the minimum and maximum values of the random numbers. Enter as z.B. \"4, 25\"");
	scanf("%d, %d", &minimum, &maximum);

	if ((randomArray = (int *)malloc(sizeof(int) * size)) == NULL)
		exit(EXIT_FAILURE);

	createRandomArray(randomArray, size, minimum, maximum);
	printArray(randomArray, size);
	
	free(randomArray);
	getchar();
	return 0;
}

void createRandomArray(int *randomArray, int size, int minimum, int maximum)
{
	for (int i = 0; i < size; i++)
		randomArray[i] = rand() % (maximum - minimum + 1) + minimum;
}

void printArray(int *randomArray, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d", randomArray[i]);
}