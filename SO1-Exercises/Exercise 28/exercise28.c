/* Author	   : Myungjun Kim
   Contents    : Exercise 28.
   Instructions: Write a function rotate2D() that rotates a 2-dimensional vector x by an angle ¥á.
				 The rotated vector x¡Ç is given by multiplying Rotation matrix and vector x: x¡Ç = Rx
 */

#define _CRT_SECURE_NO_DEPRECATE_
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void rotate2D(double *vector, double *rotatedVector, double angle);

int main(void)
{
	double vector[2] = { 2, 3 }, rotatedVector[2];
	double angle = M_PI / 3;

	rotate2D(vector, rotatedVector, angle);

	getchar();
	return 0;
}

void rotate2D(double *vector, double *rotatedVector, double angle)
{

}