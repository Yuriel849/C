#include <stdio.h>

void cleanString(void);

int main(void)
{
	cleanString();

	getchar();
	return 0;
}

void cleanString(void)
{
	char lastInput = '\n', input;

	while ((input = getchar()) != '\n')
	{
		int isFirstSpace = (lastInput == '\n') && (input == ' ');
		int isDoubleSpace = (lastInput == ' ') && (input == ' ');
		int isSpacePeriod = (lastInput == ' ') && (input == '.');

		if (!isFirstSpace && !isDoubleSpace) // Print so long as it is not a space at the start of the sentence or a double space.
			printf("%c", input);
		else if (isSpacePeriod) // Only capable of dealing with one space before the period.
			printf("\b."); // If there is a space before the period, backtrack one space and print the period.

		lastInput = input;
	}
}