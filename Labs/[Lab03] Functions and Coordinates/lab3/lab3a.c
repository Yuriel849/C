/* Author	   : Myungjun Kim
   Contents    : Calculate the hemisphere
   Instructions:
	  a) Implement a function isNorthernHemisphere() that returns a logical true only if the geographic location passed to the function is on the northern hemisphere
	  b) Implement a function isSouthernHemisphere() accordingly.
	  c) Write a program that uses some test coordinates to verify the correct return values.
 */

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>

int isNorthernHemisphere(double);
int isSouthernHemisphere(double);

int main(void)
{
	double latitude, longitude;

	latitude = 53.557078;
	longitude = 10.023109;

	// Check which hemisphere the coordinates are in
	printf("In the northern hemisphere?: %d\n", isNorthernHemisphere(latitude)); // Northern hemisphere
	printf("In the southern hemisphere?: %d\n", isSouthernHemisphere(latitude)); // Southern hemisphere

	getchar();
	return 0;
}

// Functions do nothing but return true or false values => Any further actions done where functions were called
int isNorthernHemisphere(double latitude)
{
	return (latitude > 0.0 && latitude <= 90.0);
}

int isSouthernHemisphere(double latitude)
{
	return (latitude < 0.0 && latitude >= -90.0);
}