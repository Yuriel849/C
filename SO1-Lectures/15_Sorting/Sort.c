#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void bubbleSort(int array[], int size);
void swap(int *first, int *second);

int main(void)
{
	int toSort[10] = { 666, 123, -141, 3, -777, 1, 105, 106, 0, -787 };
	int size = sizeof toSort / sizeof(int);

	for (int index = 0; index < size; index++)
		printf("%5d", toSort[index]);
	printf("\n");

	bubbleSort(toSort, size);

	for (int index = 0; index < size; index++)
		printf("%5d", toSort[index]);

	getchar();
	return 0;
}

void bubbleSort(int array[], int size)
{
	int isSwapped = 1;

	while(isSwapped)
	{
		isSwapped = 0;

		for (int index = 1; index < size; index++)
		{
			if (array[index - 1] > array[index])
			{
				swap(&array[index - 1], &array[index]);
				isSwapped = 1;
			}

		}
	}
}

void swap(int *first, int *second)
{
	int temporary;
	// Swap values of first and second
	temporary = *first;
	*first = *second;
	*second = temporary;
}