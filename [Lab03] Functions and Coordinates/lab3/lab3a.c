/* Author	   : Myungjun Kim
   Contents    : Calculate the hemisphere
   Instructions:
	  a) Implement a function isNorthernHemisphere() that returns a logical true only if the geographic location passed to the function is on the northern hemisphere
	  b) Implement a function isSouthernHemisphere() accordingly.
	  c) Write a program that uses some test coordinates to verify the correct return values.
 */

#define _CRT_SECURE_NO_DEPRECATE
#define M_PI       3.14159265358979323846
#include <stdio.h>
#include <math.h>

char isNorthernHemisphere(double);
char isSouthernHemisphere(double);

int main(void)
{
	double latitude, longitude;
	char Hemisphere = 'f'; // Default value is "false"

	latitude = 53.557078;
	longitude = 10.023109;

	// Check which hemisphere the coordinates are in
	Hemisphere = isNorthernHemisphere(latitude);

	getchar();
	return 0;
}

char isNorthernHemisphere(double latitude)
{
	if (latitude > 0)
	{
		return 'n'; // Northern hemisphere
	}
	else {
		isSouthernHemisphere(latitude);
	}
}

char isSouthernHemisphere(double latitude)
{
	if (latitude < 0)
	{
		return 's'; // Southern hemisphere
	}
	else if
	{
		return 'e'; // Equator
	}
}