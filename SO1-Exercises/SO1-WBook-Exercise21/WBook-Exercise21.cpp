/* Author	   : Myungjun Kim
   Contents    : Exercise 21.
   Instructions: Write a program that defines an array and creates an exact copy.
				 (i. e., another array with the same number of elements and values)
 */

#include <stdio.h>
#define ROWS 100

int main(void)
{
	int array01[ROWS] = { 1,2,3,4,5,4,3,2,1 }, array02[ROWS];

	for (int i = 0; i < ROWS; i++)
		array02[i] = array01[i];

	// Print both arrays to check
	for (int i = 0; i < ROWS; i++)
		printf("%d", array01[i]);
	printf("\n");

	for (int i = 0; i < ROWS; i++)
		printf("%d", array02[i]);
	printf("\n");

	getchar();
	return 0;
}