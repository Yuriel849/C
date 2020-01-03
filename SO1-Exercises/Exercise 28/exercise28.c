/* Author	   : Myungjun Kim
   Contents    : Exercise 28.
   Instructions: Write a function rotate2D() that rotates a 2-dimensional vector x by an angle a.
				 The rotated vector x' is given by multiplying Rotation matrix and vector x: x' = Rx
   Note		   : The functions cos(), sin(), etc. take radian angles as arguments.
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
	double angle = M_PI / 3; // Arbitrary angle, 60 degrees

	printf("The original vector is { %.2f %.2f }\n", vector[0], vector[1]);
	rotate2D(vector, rotatedVector, angle);
	printf("The rotated vector is { %.2f %.2f }", rotatedVector[0], rotatedVector[1]);

	getchar();
	return 0;
}

void rotate2D(double *vector, double *rotatedVector, double angle)
{
	double rotationMatrix[4] = { cos(angle), -sin(angle), sin(angle), cos(angle) };
	rotatedVector[0] = (rotationMatrix[0] * vector[0]) + (rotationMatrix[1] * vector[1]);
	rotatedVector[1] = (rotationMatrix[2] * vector[0]) + (rotationMatrix[3] * vector[1]);
}