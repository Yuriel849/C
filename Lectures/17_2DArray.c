#include <stdio.h>
#include <stdlib.h>

#define ROWS 2
#define COLUMNS 3

int sum(int *a, int rows, int columns); // passing pointer to a 1D array

int MultiDimArr_main(void)
{
	int a[ROWS][COLUMNS] = { 20, 37, 10, 16, 2, 14 }; // May add additional brackets to improve readability

	printf("Sum = %d\n", sum(*a, ROWS, COLUMNS)); // "a" is a pointer to a pointer, by dereferencing, "*a" is a pointer

	getchar();
	return 0;
}

int sum(int* a, int rows, int columns)
{
	int sum = 0;

	for (int i = 0; i < rows * columns; i++)
	{
		sum += a[i];
	}

	return sum;
}

//int sum(int(*a)[COLUMNS], int size)
//{
//	int sum = 0;
//	
//	// i & j are commonly used for for-loop variables, but meaningful names such as column & row better for readability
//	for (int i = 0; i < size * COLUMNS; i++)
//	{
//		printf("%d\n", *(*a + i));
//		sum += *(*a + i);
//	}
//
//	return sum;
//}