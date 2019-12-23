/* Author	   : Myungjun Kim
   Contents    : Exercise 31.
   Instructions: Write a function numberWords() that counts the words (i. e., the number of character sequences separated by spaces) in a string.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int transposeNxN(int *matrix, int size);
void clearBuffer(void);

int main(void)
{
	int size = 0, elements, *matrix, counter = 0;

	printf("Please enter the size of the NxN matrix as : ");
	scanf("%d", &size);
	clearBuffer();
	elements = size * size;
	matrix = (int *)calloc(elements, sizeof(int));
	printf("Please enter each element of the %dx%d matrix one at a time and hit enter", size, size);
	for (int element = 0; element < elements; element++)
		scanf("%d", matrix + element);

	transposeNxN(matrix, size);

	getchar();
	return 0;
}

int transposeNxN(int *matrix, int size)
{
	// Print the original matrix
	/*for (int row = 0; row < size; row++)
	{
		for (int column = 0; column < size; column++)
		{
			printf("%2d", *(matrix + (row * size) + column));
		}
		printf("\n");
	}*/

	// Print the transposed matrix
	for (int column = 0; column < size; column++)
	{
		for (int row = 0; row < size; row++)
		{
			printf("%2d", *(matrix + (row * size) + column));
		}
		printf("\n");
	}
}

void clearBuffer(void)
{
	while (getchar() != '\n')
		continue;
}