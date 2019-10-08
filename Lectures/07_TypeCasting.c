#define _CRT_SECURE_NO_DEPRECATE // required to use scanf() -> otherwise VS will stop program and recommend scanf_s()
#include <stdio.h>
#include <limits.h>
#include <math.h>

void main()
{
	// Variables for good parts, bad parts, the total number of parts and the ratio of bad parts to the total:
	int goodParts, badParts, total;
	float ratio;

	// Ask the user to enter the number of good parts produced:
	printf("Enter the number of good parts produced : ");
	scanf("%d", &goodParts);
	getchar();

	// Ask the user to enter the number of bad parts produced:
	printf("Enter the number of bad parts produced : ");
	scanf("%d", &badParts);
	getchar();

	// Calculate the total number of parts
	total = goodParts + badParts;

	// Calculate the ratio of bad parts to all parts:
	ratio = (double)badParts / total;

	// Print the number of bad parts, overall number of parts, and the ratio of bad parts to the total as a percentage
	printf("Bad parts: %d out of %d (%.0f%%)", badParts, total, ratio*100);

	// Wait for the user to press "Enter" before terminating
	getchar();
}