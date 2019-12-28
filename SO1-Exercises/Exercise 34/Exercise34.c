/* Author	   : Myungjun Kim
   Contents    : Exercise 34.
   Instructions: Write a function newSubstring() that receives a string and returns the substring from index m to n กร m.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

void newSubstring(char *origin, char *substring, int start, int end);
int getStringLength(char *string);

int main(void)
{
	char *substring, *origin = "Ich bin Katharina und bin eine Schneeleopard; ich bin im Jahr 2020 in Hamburg, Deustchland geboren.";
	int start = 0, end = 0, length = getStringLength(origin);

	printf("Please enter two numbers as z.B. \"1, 2\" : ");
	while (scanf("%d, %d", &start, &end)) // Receive the start and end indices for the substring
	{
		if (start < 0 || end < 0 || start > end || end > (length - 1))
			printf("Please check your input and enter valid numbers");
		else
			break;
	}

	if ((substring = (char *)malloc(sizeof(char) * (end - start + 1))) == NULL) // Dynamically allocate memory, and if it fails, terminate
		exit(EXIT_FAILURE);

	newSubstring(origin, substring, start, end);
	printf("This is the new substring cut out from the original string : %s", substring);

	getchar();
	return 0;
}

void newSubstring(char *origin, char *substring, int start, int end)
{
	int counter = 0;
	
	for (int index = start; index <= end; index++, counter++)
		substring[counter] = origin[index];

	substring[counter] = '\0';
}

int getStringLength(char *string)
{
	int counter = 0;
	while (string[counter] != '\0')
		counter++;
	return counter;
}