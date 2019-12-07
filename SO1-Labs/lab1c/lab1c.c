/* Author	   : Myungjun Kim
   Contents    : Take the user's year of birth and print the digit sum of the entered year.
   Instructions: 1. Ask the user to enter his/her year of birth.
				 2. Calculate and print the digit sum of the entered year.
   Note		   : Modified version in file lab1c_mod.c
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main()
{
	// Prepare one variable to receive input from the user, and one variable to store the sum
	int year, sum = 0;

	// Receive a 4-digit number from the user
	printf("Please enter your year of birth: ");
	scanf("%d", &year);
	getchar();

	/* One problem is that the two methods below do not show what the individual digits are, instead showing only the sum
		ex) "2016" is printed as "9", without showing 2 + 0 + 1 + 6
	 */

	 /*
	 // A year has only 4 digits, but a number with more digits may be entered, so a loop is used to handle numbers with any number of digits
	 while (year != 0) {
		 // Get the remainder of the year entered by the user when divided by 10
		 sum += year % 10;
		 // Divide the year by 10 to remove the rightmost digit
		 year /= 10;
	 }
	  */

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