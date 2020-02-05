/*
Author	 : Myungjun Kim
Contents : Solve a system of linear equations using Gauss-Jordan Elimination, and print each step.
*/

/* Header files */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */

/* Main function */
int main(void)
{
	double* system;

	createSystem(system);

	free(system);
}

/* Create system of linear equations */
void createSystem(double* system)
{
	int equations, pointerBytes, dataBytes;
	equations = getSizeOfSystem();

	pointerBytes = equations * sizeof(double *);
	dataBytes = (equations + 1) * sizeof(double);
	if ((system = (double **)malloc(pointerBytes + dataBytes)) == NULL)
		exit(EXIT_FAILURE);

	getValuesOfSystem(system);
}

/* Designate size of system (user input) */
int getSizeOfSystem(void)
{
	int equations = 0, scanResult = 0;

	while (1)
	{
		printf("Type the number of equations: ");
		scanResult = scanf("%d", &equations);

		if (!(equations <= 0 || scanResult != 1))
			break;

		printf("That entry is invalid. Enter the number of equations: ");
	}

	return equations;
}

/* Enter coefficients and solution values (user input) */
void getValuesOfSystem(double* system)
{

}

/* Find rref form of extended coefficient matrix */
/* Row multiplication with scalar (pointers) */
/* Row addition (pointers) */
/* Row exchange (pointers) */

/* Find solution from rref form of extended coefficient matrix */

/* Print extended coefficient matrix */
/* Print solution to system */