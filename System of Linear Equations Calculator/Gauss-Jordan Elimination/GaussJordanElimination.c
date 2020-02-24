/*
Author	 : Myungjun Kim
Contents : Solve a system of linear equations using Gauss-Jordan Elimination, and print each step.
*/

#define _CRT_SECURE_NO_DEPRECATE // Required to use scanf() without warnings

/* Header files */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void createSystem(double* system, int size);
int getSizeOfSystem(void);
void getValuesOfSystem(double* system, int size);
void printMatrix(double* system, int size);
void getRrefForm(double* system, int size);
void rowMultiplication(double* system, int start, int size, int multiplier);
void rowAddition(double* system, int firstRowStart, int secondRowStart, int size);
void rowExchange(double* system, int firstRowStart, int secondRowStart, int size);

/* Main function */
int main(void)
{
	double* system = NULL;
	int size;

	createSystem(system, size);

	getRrefForm(system, size);

	free(system);
}

/* Create system of linear equations */
void createSystem(double* system, int size)
{
	int dataBytes;
	size = getSizeOfSystem();

	dataBytes = size * (size + 1) * sizeof(double); // Rows * Columns of extended coefficient matrix
	if ((system = (double *)malloc(dataBytes)) == NULL)
		exit(EXIT_FAILURE); // Exit if memory allocation fails

	getValuesOfSystem(system, size);
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
void getValuesOfSystem(double* system, int size)
{
	printf("Please enter the coefficients of each equation one at a time and hit Enter.\n");
	for (int i = 0; i < size * (size + 1); i++)
	{
		scanf("%lf", &system[i]);
	}
}

/* Find rref form of extended coefficient matrix */
void getRrefForm(double* system, int size)
{

}

/* Row multiplication with scalar (pointers) */
void rowMultiplication(double* system, int start, int size, int multiplier)
{
	for (; start < start + size; start++)
	{
		system[start] *= multiplier;
	}
}

/* Row addition (pointers) */
void rowAddition(double* system, int firstRowStart, int secondRowStart, int size)
{
	for (; firstRowStart < firstRowStart + size; firstRowStart++, secondRowStart++)
	{
		system[firstRowStart] -= system[secondRowStart];
	}
}

/* Row exchange (pointers) */
void rowExchange(double* system, int firstRowStart, int secondRowStart, int size)
{
	int temp = 0; // Variable to use when swapping values

	for (; firstRowStart < firstRowStart + size; firstRowStart++, secondRowStart++)
	{
		temp = system[firstRowStart];
		system[firstRowStart] = system[secondRowStart];
		system[secondRowStart] = temp;
	}
}

/* Find solution from rref form of extended coefficient matrix */

/* Print extended coefficient matrix */
void printMatrix(double* system, int size)
{
	for (int i = 0; i < size * (size + 1); i++)
	{
		printf("%3.0f", system[i]);

		if (i != 0 && ((i + 1) % (size + 1) == 0))
			printf("\n");
	}
}

/* Print solution to system */