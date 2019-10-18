/* Author	   : Myungjun Kim
   Contents    : Version of "lab2b" using UNSIGNED LONG LONGS.
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

int main()
{
	/* ============================================================================================================================== */
	/* ================================================== USE UNSIGNED LONGS LONGS ================================================== */
	/* ============================================================================================================================== */

	/*
		Data type "unsigned long long (int)" for numbering, onField, sum
			--> no overflow or underflow occurs, all numbers are unique
				BUT when using an exponent greater than 64, overflow and underflow occurs
			--> this machine uses 64-bits for the unsigned long long data type
	 */

	// Variable for sequential numbering of chessboard fields (range 1 ~ 64)
	unsigned long long numbering = 0;
	// Variable for storing the "On Field" value
	unsigned long long onField = 0;
	// Variable for storing sum of the grains
	unsigned long long sum = 0;
	// Variable for the overall weight of all the grains;
	double totalWeight;

	// Print the header
	printf("Field |       On Field       |                Sum               \n");
	printf("------+----------------------+----------------------------------\n");

	// while loop to print lines so long as the sequential numbering variable is less than 64 in value
	while (numbering < 64) {
		onField = (unsigned long long)pow(2, numbering); // Calculate the "On Field" value; numbering starts from 0 to avoid arithmetic within pow()
		sum += onField; // Add the "On Field" value to the sum

		printf("%5llu | %20llu | %20llu (= %.1e)\n", ++numbering, onField, sum, (double)sum); // %lu is used for unsigned longs

		if (numbering % 8 == 0) { // Print divider only after multiples of 8
			printf("------+----------------------+----------------------------------\n");
		}
	}

	totalWeight = 0.000055 * sum;
	printf("\nWeight of all wheat grains (ea. grain is 55 mg) in kilograms : %.2f kg\n", totalWeight);

	printf("Weight of all grains is %.2f times the weight of worldwide wheat production in 2015 (approx. 735.8 million tons)", totalWeight / (735.8 * 1000000));

	getchar(); // Prevent program from terminating.
	return 0;
}