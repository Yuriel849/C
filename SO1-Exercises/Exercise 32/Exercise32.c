/* Author	   : Myungjun Kim
   Contents    : Exercise 32.
   Instructions: Write a function toInteger() that converts a string to an int value.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int getStringLength(char *string);
int toInteger(char *string, int length);

int main(void)
{
	char *toConvert = "123456";
	int length = getStringLength(toConvert);
	int convertedInteger = toInteger(toConvert, length);
	printf("%d", length);
	printf("String %s => Integer %d", toConvert, convertedInteger);

	getchar();
	return 0;
}

int toInteger(char *string, int length)
{
	int result = 0;

	while (length-- != 1)
	{
		// If the string contains what is not a negative sign or a digit, break
		if (string[length] != '-' || string[length] != '0' || string[length] != '1' ||
			string[length] != '2' || string[length] != '3' || string[length] != '4' ||
			string[length] != '5' || string[length] != '6' || string[length] != '7' ||
			string[length] != '8' || string[length] != '9')
			break;
	}

	return result;
}

int getStringLength(char *string)
{
	int counter = 0;
	while (string[counter] != '\0')
		counter++;
	return counter;
}