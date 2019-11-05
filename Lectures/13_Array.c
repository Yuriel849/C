#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main(void)
{
	// Declare and initialize array
	float avgTempC[12] = { 2.7, 3.8, 7.2, 11.9, 17.9, 20.2, 21.4, 21.6, 18.0, 13.3, 7.6, 4.0 }; // To assign with braces and commas, MUST DO AT DECLARATION
	int month;

	/* Get user input */
	printf("What month's average temperature would you like to know? (i.e. 1 for January, 2 for February...) :  ");
	scanf("%d", &month);
	getchar();

	/* Print average temperature in Celsius */
	printf("Your chosen month's highest average temperature is %.1f degrees in Celcius.", avgTempC[month - 1]);

	getchar();
	return 0;
}
}