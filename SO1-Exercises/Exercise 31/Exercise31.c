/* Author	   : Myungjun Kim
   Contents    : Exercise 31.
   Instructions: Write a function numberWords() that counts the words in a string.
				 (i.e., the number of character sequences separated by spaces)
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int numberWords(char* string);

int main(void)
{
	char *testString = "Let's see how many words there are in this string. There are sixteen words in all.";
	printf("There are %d words in this string.", numberWords(testString));

	getchar();
	return 0;
}

int numberWords(char* string)
{
	int numberOfWords = 1, counter = 0;

	while (string[counter] != '\0')
	{
		if (isspace(string[counter]))
			numberOfWords++;
		counter++;
	}

	return numberOfWords;
}