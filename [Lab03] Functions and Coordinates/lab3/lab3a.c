/* Author	   : Myungjun Kim
   Contents    : Calculate the hemisphere
   Instructions:
	  1. Hemispheres
		a) Implement a function isNorthernHemisphere() that returns a logical true only if the geographic location passed to the function is on the northern hemisphere
		b) Implement a function isSouthernHemisphere() accordingly.
		c) Write a program that uses some test coordinates to verify the correct return values.
	  2. Distances
		a) Implement a function localDistanceKm() that returns the distance in km between two geographic locations calculated according to (5.3).
		b) Implement a function distanceKm() that returns the distance in km between two geographic locations calculated according to (5.4).
		c) Verify that the functions return the correct distances between the HAW Hamburg and the Eiffel Tower as given in Table 5.1.
		d) Determine the missing distances to the HAW Hamburg in Table 5.1.
				  Locations			  Global	   Local
			(i)   Palma de Mallorca - 1654.5 km  - 1656.3 km
			(ii)  Las Vegas			- 8745.6 km  - 10063.9 km
			(iii) Copacabanca		- 9932.3 km  - 10255.6 km
			(iv)  Waikiki Beach		- 11625.4 km - 15266.8 km
			(v)   Surfer's Paradise - 16887.6 km - 19929.4 km
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
	if (isNorthernHemisphere(latitude) == 'n')
	{
		Hemisphere = 'n'; // Northern hemisphere
	}
	else if (isSouthernHemisphere(latitude) == 's')
	{
		Hemisphere = 's'; // Southern hemisphere
	}
	else
	{
		Hemisphere = 'e'; // Equator
	}

	getchar();
	return 0;
}

char isNorthernHemisphere(double latitude)
{
	if (latitude > 0)
	{
		return 'n';
	}
}

char isSouthernHemisphere(double latitude)
{
	if (latitude < 0)
	{
		return 's';
	}
}