/*
Author	    : Myungjun Kim
Contents    : Special exercise 07 - 
*/

/* Function prototypes */
void scaleVector2D(double a[DIM], double k);

/* Main function */
int main(void)
{
	double a1[DIM] = { 3., 4. };
	double a2[DIM] = { -2., 6. };

	/* Print vectors to the console */
	printf("Vectors:\na1 = ");
	printVector2D(a1);
	printf("\na2 = ");
	printVector2D(a2);
	printf("\n\n");

	/* Vector length */
	printf("Vector length:\n||a1|| = %.1f\n\n", vectorLength(a1));

	/* Scale vector */
	scaleVector2D(a2, 0.5);
	printf("Scale a2 with 0.5:\na2 = ");
	printVector2D(a2);
	printf("\n\n");

	/* Vector product */
	printf("Vector product:\n<a1, a2> = %.1f\n\n", vectorProduct2D(a1, a2));

	getchar();
	return 0;
}
