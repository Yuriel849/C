/* Author	   : Myungjun Kim
   Contents    : Exercise 32.
   Instructions: Write a function toInteger() that converts a string to an int value.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getStringLength(char *string);
int toInteger(char *string, int length);

int main(void)
{
	char *toConvert = "-123456";
	int length = getStringLength(toConvert);
	int convertedInteger = toInteger(toConvert, length);
	printf("String %s => Integer %d", toConvert, convertedInteger);

	getchar();
	return 0;
}

int toInteger(char *string, int length)
{
	int result = 0;
	int counter = 0;

	// First check that the string consists of only a negative sign and digits
	for (int i = 0; i < length; i++)
		if ((i != 0 && string[i] == '-') ||
			string[i] != '0' || string[i] != '1' || string[i] != '2' || string[i] != '3' || string[i] != '4' ||
			string[i] != '5' || string[i] != '6' || string[i] != '7' || string[i] != '8' || string[i] != '9')
			break;

	// Convert the string into a matching integer
	while (length-- != 0)
	{
		// Check if the first character is a negative sign, and if yes, break
		if (length == 0 && string[length] == '-')
		{
			result *= -1;
			break;
		}
		result += (string[length] - '0') * (int) pow(10, counter++);
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