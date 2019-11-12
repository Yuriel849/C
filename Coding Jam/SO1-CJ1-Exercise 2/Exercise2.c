/* Author	   : Myungjun Kim
   Contents    : Write and use a function printBinary() that prints the corresponding binary pattern of a positive integer.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int printBinary(unsigned int);

int main(void)
{
	unsigned int positiveInt = 20; // Max. size of unsigned int == 4294967295

	printBinary(positiveInt);

	return 0;
}

int printBinary(unsigned int positiveInt)
{
	int binaryPattern[32]; // int-sized array (this machine uses 4 bytes / 32 bits for the integer datatype)
	unsigned int workInt = positiveInt; // Save the value of the parameter so it can be worked on

	for (int i = 31; i >= 0; i--) // Overwrites entire array
	{
		binaryPattern[i] = workInt % 2; // Add the value of the remainder when divided by 2 to the rightmost end of the array
		workInt /= 2; // Divide the integer by 2
	}

	// Print results
	printf("When the integer is %u, the binary pattern is ", positiveInt);
	for (int i = 0; i <= 31; i++) // Print the array
	{
		printf("%d", binaryPattern[i]);
	}
	printf(".\n");

	return 0;
}