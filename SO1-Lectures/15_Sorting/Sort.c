#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void bubbleSort(int *array, int size);
void swap(int *first, int *second);
void singlePassSort(int *array, int size);

int main(void)
{
	int toSort[SIZE] = { 666, 123, -141, 3, -777, 1, 105, 106, 0, -787 };
	clock_t start;
	unsigned timeInMs;

	for (int index = 0; index < SIZE; index++)
		printf("%5d", toSort[index]);
	printf("\n");

	start = clock();
	bubbleSort(toSort, SIZE);
	timeInMs = (unsigned)(((clock() - start) * 1000) / CLOCKS_PER_SEC);

	printf("Time taken (bubble sort) : %u ms\n", timeInMs);
	for (int index = 0; index < SIZE; index++)
		printf("%5d", toSort[index]);
	
	getchar();
	return 0;
}

// Sort array of size with quicksort

// Sort array of size with single-pass sort
void singlePassSort(int *array, int size)
{

}

// Sort array of size with bubble sort
void bubbleSort(int *array, int size)
{
	int isSwapped; // Flag variable to control do-while loop
	int lastIndex = size - 1;

	do {
		isSwapped = 0;
		for (int index = 1; index < lastIndex; index++)
		{
			if (array[index - 1] > array[index])
			{
				swap(&array[index - 1], &array[index]);
				isSwapped = 1;
			}
		}
		lastIndex--;
	} while (isSwapped);
}

// Swap values of first and second
void swap(int *first, int *second)
{
	int temporary = *first;
	*first = *second;
	*second = temporary;
}