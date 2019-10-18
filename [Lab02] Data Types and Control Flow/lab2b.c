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
	// Variable for sequential numbering of chessboard fields (range 1 ~ 64)
	int numbering = 0;
	// Variable for storing the "On Field" value
	int onField = 0;
	// Variable for storing sum of the grains
	int sum = 0;

	// Print the header
	printf("Field | On Field | Sum\n");
	printf("------+----------+---------------------\n");

	// while loop to print lines so long as the sequential numbering variable is less than 64 in value
	while (numbering < 64) {
		onField = (int) pow(2, numbering); // Calculate the "On Field" value; numbering starts from 0 to avoid arithmetic within pow()
		sum += onField; // Add the "On Field" value to the sum

		printf("%5d | %8d | %20d\n", ++numbering, onField, sum);

		if (numbering % 8 == 0) { // Print divider only after multiples of 8
			printf("------+----------+---------------------\n");
		}
	}

	getchar(); // Prevent program from terminating.
	return 0;
}