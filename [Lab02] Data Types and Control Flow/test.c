#include <stdio.h>
#include <math.h>

int test_main()
{
	// Variable for sequential numbering of chessboard fields (range 1 ~ 64)
	unsigned numbering = 31;
	// Variable for storing the "On Field" value
	unsigned onField = 0;
	// Variable for storing sum of the grains
	unsigned sum = 0;

	onField = (unsigned) pow(2, numbering); // Calculate the "On Field" value; numbering starts from 0 to avoid arithmetic within pow()

	printf("%5d | %8u\n", ++numbering, (unsigned) pow(2, 33));

	getchar(); // Prevent program from terminating.
	return 0;
}