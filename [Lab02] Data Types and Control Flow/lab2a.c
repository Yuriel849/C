/* Author	   : Myungjun Kim
   Contents    : Print a chessboard in a two-dimensional order to the console.
   Instructions: 1. Use for loops to print all fields of a chessboard in a two-dimensional order to the console.
				 2. Rows are labeled 8 (top) to 1 (bottom).
				 3. Columns are labeled a (left) to h (right).
 */

#include <stdio.h>

int lab2a_main()
{	
	// Variables to represent the row numbers and column characters.
	int rowNumber = 8;
	char columnChar = 'a';

	/* =========================================================================================================================== */
	/* ======================================================= VERSION 1 ========================================================= */
	/* =========================================================================================================================== */

	//// Use two for loops, one inside the other. The outer loop prints each row.
	//for (int i = (2 * rowNumber + 1); i > 0; i--) {
	//	if (i % 2 == 1) { // If this is an odd-numbered row, print pluses and dashes.
	//		printf("\n+----+----+----+----+----+----+----+----+\n");
	//	}
	//	else { // If this is an even-numbered row, print bars and identifiers with the inner for loop.
	//		printf("| "); // First leftmost bar.
	//		// The inner loop prints the contents of each row.
	//		for (int j = columnChar; j <= 'h'; j++) { // columnChar remains unchanged
	//			printf("%c%d | ", j, i / 2);
	//		}
	//	}
	//}


	/* =========================================================================================================================== */
	/* ======================================================= VERSION 2 ========================================================= */
	/* =========================================================================================================================== */

	printf("+----+----+----+----+----+----+----+----+\n");

	// Use two for loops, one inside the other. The outer loop prints each row.
	for (int i = rowNumber; i > 0; i--) {
		printf("| "); // First leftmost bar.
		// The inner loop prints the contents of each row.
		for (int j = columnChar; j <= 'h'; j++) { // columnChar remains unchanged
			printf("%c%d | ", j, i / 2);
		}

		// After printing the content row, print a divider row.
		printf("\n+----+----+----+----+----+----+----+----+\n");
	}
}