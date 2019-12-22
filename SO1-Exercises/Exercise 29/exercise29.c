/* Author	   : Myungjun Kim
   Contents    : Exercise 29.
   Instructions: Write a function that receives a matrix A and prints the transposed matrix AT
 */

#include <stdio.h>

int transposeMatrix(int *matrix, int rows, int columns);

int main(void)
{
	int matrix[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	transposeMatrix(matrix, 3, 3);

	getchar();
	return 0;
}

int transposeMatrix(int *matrix, int rows, int columns)
{
	// Print the original matrix
	/*for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			printf("%2d", *(matrix + (row*columns) + column));
		}
		printf("\n");
	}*/

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