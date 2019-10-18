/* Author	   : Myungjun Kim
   Contents    : Original version of "lab2b", using SIGNED INTEGERS.
   Instructions: 1. Print a table with the following information.
					a. Sequential numbering of the chessboard fields (1 to 64)
					b. Number of grains on the specific field (i. e., 1, 2, 4, 8, . . . )
					c. Sum of grains on all fields up to the specific field (e. g., 1 + 2 + 4 = 7 for the third field)
				 2. Vary data types used for number of grains to be unsigned short, unsigned, unsigned long and unsigned long long.
					Explain observations and determine number of bits used on this machine to represent each of these data types.
				 3. Determine overall weight of all wheat grains (assuming weight of 55 mg / grain).
				 4. How does overall weight of all grains relate to weight of worldwide wheat production in 2015, about 735.8 million tons?
 */

#include <stdio.h>
#include <math.h>

int lab2b_signed_int_main()
{
	/* ============================================================================================================================== */
	/* ================================================== USE SIGNED INTEGERS ======================================================= */
	/* ============================================================================================================================== */

	/*
		Data type "(signed) int" for numbering, onField, sum
			--> from numbering == 32, onField shows -2147483648 while sum alternates between -1 & 2147483647
				onField is always -2147483648 because the figure is always larger than the maximum value of signed int and overflow occurs
				sum alternates between -1 & 2147483647 because adding the value of onField results in underflow and overflow
			--> this machine uses 32-bits for the signed int data type
	 */
	
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

		printf("%5d | %8d | %7d (= %.1e)\n", ++numbering, onField, sum, (double) sum);

		if (numbering % 8 == 0) { // Print divider only after multiples of 8
			printf("------+----------+---------------------\n");
		}
	}

	getchar(); // Prevent program from terminating.
	return 0;
}