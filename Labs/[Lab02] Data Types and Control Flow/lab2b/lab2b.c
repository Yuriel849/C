/* Author	   : Myungjun Kim
   Contents    : Version of "lab2b" using UNSIGNED LONG LONGS; designated as the main "lab2b" file because instructions require unsigned long long data type.
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

int main()
{
	/*
		Data type "unsigned long long (int)" for numbering, onField, sum
			--> no overflow or underflow occurs, all numbers are unique
				BUT when using an exponent greater than 64, overflow and underflow occurs
			--> this machine uses 64-bits for the unsigned long long data type

		Number of all wheat grains is 18,446,744,073,709,551,615 (18,446,744 trillion grains)
		Weight of all wheat grains is 1,014,570,924,054,025.38 kg (1,014.57 trillion kilograms).
		Weight of all wheat grains is 1,378.87 times the weight of 2015 worldwide wheat production.
	 */

	// Variable for sequential numbering of chessboard fields (range 1 ~ 64)
	int numbering = 1;
	// Variable for storing the "On Field" value
	unsigned long long onField = 1;
	// Variable for storing sum of the grains
	unsigned long long sum = 1;
	// Variable for the overall weight of all the grains;
	double totalWeight;

	// Print the header
	printf("Field |       On Field       |                Sum               \n");
	printf("------+----------------------+----------------------------------\n");

	// Print lines so long as the sequential numbering variable is less than or equal to 64 in value
	while (numbering <= 64)
	{
		printf("%5d | %20llu | %20llu (= %.1e)\n", numbering, onField, sum, (double)sum); // %llu is used for unsigned long longs

		if (numbering % 8 == 0)
		{ // Print divider only after multiples of 8
			printf("------+----------------------+----------------------------------\n");
		}

		onField *= 2; // Multiple the "On Field" value by 2 to get the next power of 2
		sum += onField; // Add the "On Field" value to the sum
		numbering++; // Increment numbering after one iteration
	}

	totalWeight = 0.000055 * sum;
	printf("\nWeight of all wheat grains (ea. grain is 55 mg) in kilograms : %.2f kg\n", totalWeight);

	printf("Weight of all grains is %.2f times the weight of worldwide wheat production in 2015 (approx. 735.8 million tons)", totalWeight / (735.8 * 1000000));

	getchar(); // Prevent program from terminating.
	return 0;
}