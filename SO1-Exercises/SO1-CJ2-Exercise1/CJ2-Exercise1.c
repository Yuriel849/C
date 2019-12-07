/* Author	   : Myungjun Kim
   Contents    : See if word entered is a subset of a string.
   Instructions: Target string is "Life is what happens when you are busy making other plans."
   Note		   : INCOMPLETE
				 z.B. "ife" is considered valid.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *target = "Life is what happens you are busy making other plans.";
	char input[10];
	int targetLength = getStringLength(target);
	int inputLength;

	printf("Please enter one word and hit enter: ");
	scanf("%10s", input);
	while (getchar() != '\n')
		continue;

	inputLength = getStringLength(input);

	for (int i = 0, index = 0, counter = inputLength; i < targetLength; i++)
	{
		if (input[index] == target[i])
		{
			index++;
			counter--;
		}
		else
		{
			index = 0;
			counter = inputLength;
		}

		if (counter == 1)
			printf("Yes, the word you entered is a subset of this sentence.\n");
	}

	printf("\nTerminating.");

	getchar();
	return 0;
}

int getStringLength(const char *string)
{
	int length = 0;
	while (string[length++] != '\0')
		continue;
	return length;
}