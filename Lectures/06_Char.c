#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <limits.h>
#include <math.h>

int C_main()
{
	//char a = 'ab'; // can just put the number 97 (w/o single quotation marks)
	//// char datatype can be printed as both a character and an integer
	//printf("a: %c\n", a);
	//printf("a: %d\n", a);

	char character;

	/* Get user input */
	printf("Please enter one (1) character: ");
	scanf("%c", &character);
	// character = getchar(); -> if like this, character is the linebreak (because "enter" is typed to end scanf(), picked up by getchar(), then assigned to character)
	getchar();

	printf("You have entered this character: %c (%d)\n", character, character);

	getchar();
	return 0;
}