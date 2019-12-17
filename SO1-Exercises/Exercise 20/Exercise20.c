/* Author	   : Myungjun Kim
   Contents    : Exercise 20.
   Instructions: Write a program that creates and prints two int arrays with 100 elements with value 0.
				 Use a loop and a list, respectively, to initialize the values.
 */

#include <stdio.h>

int main(void)
{
	int array01[100] = { 0 };
	int array02[100];

	for (int i = 0; i < 100; i++)
		array02[i] = 0;

	// Print both arrays to check
	for (int i = 0; i < 100; i++)
		printf("%d", array01[i]);
	printf("\n");

	for (int i = 0; i < 100; i++)
		printf("%d", array02[i]);
	printf("\n");

	getchar();
	return 0;
}