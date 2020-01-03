/* Author	   : Myungjun Kim
   Contents    : Exercise 26.
   Instructions: Write a program that asks users to enter data in the format key=value. Print key and value in separate rows to the console.
 */

#define _CRT_SECURE_NO_DEPRECATE_
#define SIZE 256

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char input[SIZE];

	printf("Please enter data in the format key=value { z.B. city=Hamburg } : \n");
	if (fgets(input, SIZE, stdin) != NULL)
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (!(input[i] != '='))
				printf("\n");
			else if (!(input[i] != '\0'))
				break;
			else
				printf("%c", input[i]);
		}
	}

	getchar();
	return 0;
}