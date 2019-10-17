/* Author	   : Myungjun Kim
   Contents    : 
   Instructions: 1. Print a table with the following information.
					a. Sequential numbering of the chessboard fields (1 to 64)
					b. Number of grains on the specific field (i. e., 1, 2, 4, 8, . . . )
					c. Sum of grains on all fields up to the specific field (e. g., 1 + 2 + 4 = 7 for the third field)   
 */

#include <stdio.h>
#include <math.h>

int main()
{
	// Variable to be the sequential numbering of the chessboard fields (range 1 ~ 64)
	double numbering = 1;
	// Variable to store the sum of the grains
	int sum = 0;
	// Variable to store the "On Field" value
	int onField = 0;

	// while loop to print lines so long as the sequential numbering variable is less than 64 in value
	while (numbering <= 64) {
		// Calculate the "On Field" value
		onField = (int) pow(2, numbering-1);
		sum += onField;

		printf("%.f | %4d | %4d\n", numbering++, onField, sum);
	}

}