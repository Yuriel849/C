/* Author	   : Myungjun Kim
   Contents    : Implementation of a simple calculator in C for arithmetic operations
   Instructions: 1. Define two integer variables with values 7 and 3, respectively.
				 2. Generate the console output below.
					a) The printf() function must insert the operand values 7 and 3 from the integer variables.
					b) The results must be calculated using algorithmic operations.
 */

#include <stdio.h>

int lab1a_main()
{
	// Fix values of variables
	int seven = 7, three = 3;

	// Perform basic arithmetic operations
	printf("Simple calculator : \n");
	printf("------------------\n");
	printf("1st operand: %d\n", seven);
	printf("2nd operand: %d\n\n", three);
	printf("%d + %d = %d\n", seven, three, seven + three);
	printf("%d - %d = %d\n", seven, three, seven - three);
	printf("%d * %d = %d\n", seven, three, seven * three);
	printf("%d / %d = %d\n", seven, three, seven / three);
	printf("%d %% %d = %d", seven, three, seven % three);

	getchar();
	return 0;
}