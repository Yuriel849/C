/* Author	   : Myungjun Kim
   Contents    : Make a function that concatenates two strings.
   Note		   : INCOMPLETE
				 Not performing as intended in VS2017 (operational in VS2019)
 */

#include <stdio.h>
#include <stdlib.h>

char* concatString(char* first, char*second, int firstSize, int secondSize);
int getStringSize(char* string);

int main(void)
{
	// Make three strings
	char* firstString = "Hochschule fur Angewandte";
	char* secondString = "Wissenschaften Hamburg";
	char *combinedString;
	int firstSize, secondSize;

	// Calculate sizes of two strings
	firstSize = getStringSize(firstString);
	secondSize = getStringSize(secondString);

	// Pass two strings to a function
	combinedString = concatString(firstString, secondString, firstSize, secondSize);

	// Print single string
	printf("%s", combinedString);

	getchar();
	return 0;
}

char* concatString(char* first, char* second, int firstSize, int secondSize)
{
	// Calculate size of combined string
	char* combinedString = (char *)malloc(firstSize + secondSize + 1);

	// Add first string to combined string and put space after first string
	for (int i = 0; i < firstSize - 1; i++)
	{
		combinedString[i] = first[i];
	}
	combinedString[firstSize - 1] = ' ';

	// Add second string to combined string and put period after first string
	for (int i = 0; i < secondSize; i++)
	{
		combinedString[firstSize + i] = second[i];
	}
	combinedString[firstSize + secondSize] = '\0';

	// Return combined String
	return combinedString;
}

int getStringSize(char* string)
{
	int counter = 0;

	while (string[counter++] != '\0')
		continue;

	return counter;
}