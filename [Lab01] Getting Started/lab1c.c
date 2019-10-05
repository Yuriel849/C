/* Author	   : Myungjun Kim
   Contents    : Take the user's year of birth and print the digit sum of the entered year.
   Instructions: 1. Ask the user to enter his/her year of birth.
				 2. Calculate and print the digit sum of the entered year.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main()
{
	int year, sum = 0;

	printf("Please enter your year of birth: ");
	scanf("%d", &year); // The user enters a 4-digit number.
	getchar();


	//// While a year has only 4 digits, it is possible that a number with more digits may be entered, so a loop is used to handle numbers with any number of digits
	//while (year != 0) {
	//	// Get the remainder of the year entered by the user when divided by 10
	//	sum += year % 10;
	//	// Divide the year by 10 to remove the rightmost digit
	//	year /= 10;
	//}

	// Get the remainder of the year entered by the user when divided by 10
	sum += year % 10;
	// Divide the year by 10 to remove the rightmost digit
	year /= 10;
	// Get the remainder when divided by 10
	sum += year % 10;
	// Divide the year by 10 to remove the rightmost digit
	year /= 10;
	// Get the remainder when divided by 10
	sum += year % 10;
	// Divide the year by 10 to remove the rightmost digit
	year /= 10;
	// Get the remainder when divided by 10
	sum += year % 10;

	printf("The digit sum of your year of birth is %d", sum);

	getchar();
	return 0;
}