/* Author	   : Myungjun Kim
   Contents    : Exercise 37 ~ 39.
   Instructions: (37) Declare and apply a structure vector2D for a mathematical 2-D vector.
				 (38) Write and apply a function to get the absolute value of a vector of type vector2D.
				 (39) Write and apply a function that multiplies a vector of type vector2D with a 2 ¡¿ 2 matrix of type double[2][2].
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int x1;
	int x2;
} vector2D;

double absoluteVal(vector2D);
vector2D vectorMatrixMultiplication(vector2D);

int main(void)
{
	vector2D testVector = { 2, 3 }, result;
	double abs;

	abs = absoluteVal(testVector);
	result = vectorMatrixMultiplication(testVector);

	printf("The vector \"testVector\" is { %d, %d }\n", testVector.x1, testVector.x2);
	printf("Absolute value of the vector \"testVector\" is %f\n", abs);
	printf("Result of vector-matrix multiplication is { %d, %d }\n", result.x1, result.x2);

	getchar();
	return 0;
}

double absoluteVal(vector2D vector) // Find the absolute value of a vector == Find the distance from the origin (0,0)
{
	return sqrt((vector.x1 * vector.x1) + (vector.x2 * vector.x2));
}

vector2D vectorMatrixMultiplication(vector2D vector)
{
	double matrix[2][2] = { { 1, 3 }, { 2, 4 } };
	vector2D returnVector;

	returnVector.x1 = (vector.x1 * matrix[0][0]) + (vector.x2 * matrix[1][0]);
	returnVector.x2 = (vector.x1 * matrix[0][1]) + (vector.x2 * matrix[1][1]);

	return returnVector;
}