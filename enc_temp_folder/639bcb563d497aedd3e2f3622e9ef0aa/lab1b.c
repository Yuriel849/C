/* Author	   : Myungjun Kim
   Contents    : Modified version of the simple calculator implemented in file lab1a.c
   Instructions: 1. Users enter the operands using the keyboard.
				 2. The console output stays as it is (with the values depending on the user input).
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main()
{
	int inputOne, inputTwo;

	printf("Please enter one integer and press Enter.");
	scanf("%d", &inputOne);
	printf("Please enter another integer and press Enter.");
	scanf("%d", &inputTwo);
	getchar();

	printf("Simple calculator : \n");
	printf("------------------\n");
	printf("1st operand: %d\n", inputOne);
	printf("2nd operand: %d\n\n", inputTwo);
	printf("%d + %d = %d\n", inputOne, inputTwo, inputOne + inputTwo);
	printf("%d - %d = %d\n", inputOne, inputTwo, inputOne - inputTwo);
	printf("%d * %d = %d\n", inputOne, inputTwo, inputOne * inputTwo);
	printf("%d / %d = %d\n", inputOne, inputTwo, inputOne / inputTwo);
	printf("%d %% %d = %d", inputOne, inputTwo, inputOne % inputTwo);

	getchar();
	return 0;
}