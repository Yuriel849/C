#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main(void)
{
	int raw[15] = { 95, 91, 222, 93, 95, 73, 84, 4, 34, 545, 55, 128, 83, 94, 99 };
	int binomial[15]; // Use a new array to avoid changing the original data
	int size = sizeof raw / sizeof raw[0]; // Dynamically determine the size of the array raw (no. of elements in the array)

	// First and last elements are not filtered, so process separately
	binomial[0] = raw[0];
	binomial[size - 1] = raw[size - 1];

	// Run array through binomial filter
	for (int i = 1; i < size - 1; i++) {
		binomial[i] = (raw[i - 1] + 2 * raw[i] + raw[i + 1]) / 4; // Shifting bit patterns is even faster than dividing by 4
	}

	// Print raw array
	for (int i = 0; i < size; i++)
		printf("%4d", raw[i]);
	printf("\n");
	// Print binomial array
	for (int i = 0; i < size; i++)
		printf("%4d", binomial[i]);

	getchar();
	return 0;
}