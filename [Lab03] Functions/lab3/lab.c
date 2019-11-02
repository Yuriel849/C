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
double localDistanceKm(double, double, double, double);
double distanceKm(double, double, double, double);

int main(void)
{
	double latitudeX, longitudeX, latitudeY, longitudeY, distance;
	char Hemisphere = 'f'; // Default value is "false"

	// Coordinates of HAW Hamburg
	latitudeX = 53.557078;
	longitudeX = 10.023109;

	// Coordinates of other location
	latitudeY = -28.002695;
	longitudeY = -153.431781;

	// Check which hemisphere the coordinates are in
	if (isNorthernHemisphere(latitudeX) == 'n')
	{
		Hemisphere = 'n'; // Northern hemisphere
	}
	else if (isSouthernHemisphere(latitudeX) == 's')
	{
		Hemisphere = 's'; // Southern hemisphere
	}
	else
	{
		Hemisphere = 'e'; // Equator
	}

	// Calculate the distance between the two sets of coordinates
	distance = localDistanceKm(latitudeX, longitudeX, latitudeY, longitudeY);
	printf("The local distance between these two points is %.1lf km\n", distance);

	// More accurately calculate the distance between the two sets of coordinates
	distance = distanceKm(latitudeX, longitudeX, latitudeY, longitudeY);
	printf("The global distance between these two points is %.1lf km\n", distance);

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

double localDistanceKm(double latitudeX, double longitudeX, double latitudeY, double longitudeY)
{
	double deltaX, deltaY;

	// Calculate deltaY as 111.3 * | latitudeX - latitudeY |
	deltaY = 111.3 * fabs(latitudeX - latitudeY);

	// Calculate deltaX as 111.3 * cos((latitudeX + latitudeY) / 2) * | longitudeX - longitudeY |
	deltaX = 111.3 * cos((latitudeX + latitudeY) * M_PI / 180.0 / 2) * fabs(longitudeX - longitudeY);

	// Calculate and return the distance between the two points
	return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}

double distanceKm(double latitudeX, double longitudeX, double latitudeY, double longitudeY)
{
	double sinLatX, sinLatY, cosLatX, cosLatY, cosLong;

	// Convert degrees into radians;
	sinLatX = sin(latitudeX * M_PI / 180.0);
	sinLatY = sin(latitudeY * M_PI / 180.0);
	cosLatX = cos(latitudeX * M_PI / 180.0);
	cosLatY = cos(latitudeY * M_PI / 180.0);
	cosLong = cos((longitudeY - longitudeX) * M_PI / 180.0);

	// Calculate and return the distance between two points
	return 6378.388 * acos((sinLatX * sinLatY) + (cosLatX * cosLatY * cosLong));
}