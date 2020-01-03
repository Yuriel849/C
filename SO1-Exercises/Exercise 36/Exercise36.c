/* Author	   : Myungjun Kim
   Contents    : Exercise 36.
   Instructions: Write a function createRandomMatrix() that allocates a 2-D int array and initializes it with random numbers.
				 The function shall invoke malloc() only once, allocating memory for the row pointers and matrix data at the same time,
				 and initialize the row pointers appropriately. Users enter the matrix size and the minimum and maximum random value.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

void createRandomMatrix(int **randomMatrix, int rows, int columns, int minimum, int maximum);
void printArray(int **randomMatrix, int rows, int columns);

int main(void)
{
	int rows = 0, columns = 0, minimum = 0, maximum = 0;
	int **randomMatrix = 0;

	printf("Please create a two-dimensional array of integers filled with random numbers.\nFirst, enter the size of the array z.B. \"2,5\"\n");
	scanf("%d, %d", &rows, &columns);
	printf("Next, please choose the minimum and maximum values of the random numbers. Enter as z.B. \"4, 25\"");
	scanf("%d, %d", &minimum, &maximum);

	createRandomMatrix(randomMatrix, rows, columns, minimum, maximum);
	printArray(randomMatrix, rows, columns);

	free(randomMatrix);
	getchar();
	return 0;
}

void createRandomMatrix(int **randomMatrix, int rows, int columns, int minimum, int maximum)
{
	/* Allocate memory for matrix */
	int pointerBytes = rows * sizeof(int *);
	int rowBytes = columns * sizeof(int);
	int *data; // Pointer to start of matrix data
	if ((randomMatrix = (int **)malloc(pointerBytes + rows * rowBytes)) == NULL)
		exit(EXIT_FAILURE);

	/* Initialize pointers to rows */
	data = (int *)(randomMatrix + rows);
	for (int y = 0; y < rows; y++)
		randomMatrix[y] = data + y * columns;

	for (int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			randomMatrix[i][j] = rand() % (maximum - minimum + 1) + minimum;
}

void printArray(int **randomMatrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			printf("%d", randomMatrix[i][j]);
}