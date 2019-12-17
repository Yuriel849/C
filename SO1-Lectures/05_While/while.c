#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main()
{
	// Note: The printf() function returns the number of characters printed.
	int numberChar = printf("Aus Hansestadt Hamburg, die schoenste Stadt in Deutschland!!!!!\n");
	int index = 0;

	while (--numberChar > 0) { // first decrement by one, second make the comparison with the number 0
		/* while (numberChar-- > 1)
			identical to the above expression, first compares with the number 1 before decrementing by one
			number 1 instead of 0, because the linebreak itself is a character and would cause the loop to run one more time
		 */

		 //printf("-");
		printf("%d", index++);

		index %= 10; // Always calculates remainder to prevent index from becoming a two-digit number
	}

	getchar();
	return 0;
}