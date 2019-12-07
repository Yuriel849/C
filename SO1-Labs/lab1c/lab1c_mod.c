/* Author	   : Myungjun Kim
   Contents    : Take the user's year of birth and print the digit sum of the entered year.
   Note		   : Modified version of file lab1c.c to use integer field widths with scanf().
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int lab1c_mod_main()
{
	// Prepare one variable to receive input from the user, and one variable to store the sum
	int firstDigit, secondDigit, thirdDigit, fourthDigit, sum = 0;

	// Receive a 4-digit number from the user, reading each digit individually and saving in a separate variable
	printf("Please enter your year of birth: ");
	scanf("%1d%1d%1d%1d", &firstDigit, &secondDigit, &thirdDigit, &fourthDigit);
	getchar();

	sum = firstDigit + secondDigit + thirdDigit + fourthDigit;

	printf("The digit sum of your year of birth is %d", sum);

	getchar();
	return 0;
}