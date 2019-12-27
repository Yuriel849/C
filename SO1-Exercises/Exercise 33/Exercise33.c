/* Author	   : Myungjun Kim
   Contents    : Exercise 33.
   Instructions: Write a function cleanString() to remove leading spaces, double spaces, and spaces before a period ¡®.¡¯ in a string.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

void cleanString(char *origin, char *destination);
int getStringLength(char *string);

int main(void)
{
	char *cleaned, *toClean = "      This is Musya,     the most beautiful  16-year-old cat   you'll ever see    .";
	int length = getStringLength(toClean);
	cleaned = (char *)calloc(length, sizeof(char));

	printf("Before cleaning : %s\n", toClean);
	cleanString(toClean, cleaned);
	printf("After cleaning  : %s", cleaned);

	getchar();
	return 0;
}

void cleanString(char *origin, char *destination)
{
	int counter = 0, index = 0;

	while (origin[counter] != '\0')
	{
		if((origin[counter] != ' ' || index != 0) && !(origin[counter] == ' ' && origin[counter + 1] == ' ') && !(origin[counter] == ' ' && origin[counter + 1] == '.'))
		{
			destination[index++] = origin[counter];
		}
		counter++;
	}
}

int getStringLength(char *string)
{
	int counter = 0;
	while (string[counter] != '\0')
		counter++;
	return counter;
}