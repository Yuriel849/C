/*
Author	    : Myungjun Kim
Contents    : Special exercise 02 - Implement a function to invert a given string
				  and a function to count the number of occurences of a given character within a given string.
*/

#include <stdlib.h>
#include <stdio.h>

char *invertString(const char*);
int countChar(const char*, const char);

int main(void)
{
	char *originalString = "Willkommen in Hamburg!";

	printf("Original : %s\n", originalString);
	printf("Inverted : %s\n", invertString(originalString));
	printf("Count 'e': %d", countChar(originalString, 'e'));

	getchar();
	return 0;
}

char *invertString(const char* originalString)
{
	char *returnString;
	int size = 0, counter = 0;

	while (originalString[counter++] != '\0') /*Get size of the parameter string*/
		size++;

	if ((returnString = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		exit(EXIT_FAILURE);

	for (int i = 0; i < size; i++)
		returnString[i] = originalString[size - 1 - i];
	returnString[size] = '\0';

	return returnString;
}

int countChar(const char* stringToCheck, const char charToCount)
{
	int counter = 0, index = 0;

	while (stringToCheck[index] != '\0')
	{
		if (stringToCheck[index] == charToCount)
			counter++;
		index++;
	}

	return counter;
}