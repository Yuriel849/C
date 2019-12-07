/* Author	   : Myungjun Kim
   Contents    : Print a chessboard in a two-dimensional order to the console.
   Instructions: 1. Use for loops to print all fields of a chessboard in a two-dimensional order to the console.
				 2. Rows are labeled 8 (top) to 1 (bottom).
				 3. Columns are labeled a (left) to h (right).
 */

#include <stdio.h>

int main()
{
	// Variables to represent the row numbers and column characters.
	int rowNumber = 8;
	char columnChar = 'a';

	printf("+----+----+----+----+----+----+----+----+\n");

	// Use two for loops, one inside the other. The outer loop prints each row.
	for (int i = rowNumber; i > 0; i--) {
		printf("| "); // First leftmost bar.
		// The inner loop prints the contents of each row.
		for (int j = columnChar; j <= 'h'; j++) // columnChar remains unchanged
		{
			printf("%c%d | ", j, i / 2);
		}

		// After printing the content row, print a divider row.
		printf("\n+----+----+----+----+----+----+----+----+\n");
	}

	getchar();
	return 0;
}