#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char** a;
	int rows = 2, columns = 3;

	a = (int**)malloc(rows * sizeof(int*)); // Memory allocation

	for (int i = 0; i < rows; i++)
	{
		a[i] = (int*)malloc(columns * sizeof(int));
	}

	// Data
	a[0][0] = 42;
	a[0][1] = 4;
	a[0][2] = 2;
	a[1][0] = 11;
	a[1][1] = 1001;
	a[1][2] = -1111;

	for(int y = 0; y < rows; y++) // Printf
	{
		for(int z = 0; z < columns; z++)
		{
			printf("%6d", a[y][z]);
		}
		putchar('\n');
	}

	// Free up memory
	for (int i = 0; i < rows; i++)
		free(a[i]);
	free(a);

	getchar();
	return 0;
}