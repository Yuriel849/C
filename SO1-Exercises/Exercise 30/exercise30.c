/* Author	   : Myungjun Kim
   Contents    : Exercise 30.
   Instructions: Write a function transposeNxN() that transposes a N ¡¿ N matrix A
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int transposeNxN(int *matrix, int rows, int columns);

int main(void)
{
	int rows = 0, columns = 0;
	int *matrix;

	printf("Please enter the size of the matrix as : rows, columns");
	scanf("%d, %d", &rows, &columns);
	matrix = (int *)calloc(rows * columns, sizeof(int));
	printf("Please enter the elements of the matrix one at a time and hit enter");
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			scanf("%d", );
		}
	}

	transposeNxN(matrix, 3, 3);

	getchar();
	return 0;
}

int transposeNxN(int *matrix, int rows, int columns)
{
	// Print the original matrix
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			printf("%2d", *(matrix + (row*columns) + column));
		}
		printf("\n");
	}

	// Print the transposed matrix
	for (int column = 0; column < columns; column++)
	{
		for (int row = 0; row < rows; row++)
		{
			printf("%2d", *(matrix + (row*columns) + column));
		}
		printf("\n");
	}
}