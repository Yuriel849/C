#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main()
{
	// Note: The scanf() function returns the number of inputs correctly read and assigned.
	int input = 0;
	int sum = 0;
	int counter = 0;

	while (scanf("%d", &input)) { // scanf() will ignore linebreaks, spaces, etc. scanf() will only read and assign integers, leave anything else untouched and return 0.
		sum += input;
		counter++;
	}
	getchar(); // scanf() only reads integers, so a char is left unread => this getchar() reads the leftover character
	getchar(); // this getchar() reads the enter key of the last input
	// this code assumes the user enters only one char, or only one number & char => if the user enters two or more char, failure

	printf("The average value of %d number(s) is %.2f", counter, (float) sum / counter);

	getchar();
	return 0;
}