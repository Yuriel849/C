/* Author	   : Myungjun Kim
   Contents    : Print a chessboard in a two-dimensional order to the console.
   Instructions: 1. Use for loops to print all fields of a chessboard in a two-dimensional order to the console.
				 2. Rows are labeled 8 (top) to 1 (bottom).
				 3. Columns are labeled a (left) to h (right).
   Note		   : Modified version of file lab2a.c to receive input from the user with scanf().
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int lab2a_mod_main()
{	
	// Variables to represent the row numbers and column characters.
	int rowNumber = 8; // Default value.
	char columnChar = 'a'; // Default value.
	int rowFlag = 1, charFlag = 1; // Default values are 'true'.

	// Use a while loop to receive input from the user and check that the input is valid.
	while (rowFlag == 1 && charFlag == 1) {
		// Row number must be between 1 ~ 26.
		printf("Please enter one number between 1 and 26.");
		scanf("%d", &rowNumber);
		if (!(rowNumber >= 1 && rowNumber <= 26)) {
			continue;
		}

		// Column character must be between 'a' and 'z'.
		printf("Please enter one character between a and z.");
		scanf("%c", &columnChar);
		if (!(columnChar >= 'a' && columnChar <= 'z')) {
			continue;
		}
	}

	// Use two for loops, one inside the other. The outer loop prints each row.
	for (int i = (2 * rowNumber + 1); i > 0; i--) {
		if (i % 2 == 1) { // If this is an odd-numbered row, print pluses and dashes.
			printf("\n+----+----+----+----+----+----+----+----+\n");
		}
		else { // If this is an even-numbered row, print bars and identifiers with the inner for loop.
			printf("| "); // First leftmost bar.
			// The inner loop prints the contents of each row.
			for (int j = columnChar; j <= 'h'; j++) { // columnChar remains unchanged
				printf("%c%d | ", j, i / 2);
			}
		}
	}
}