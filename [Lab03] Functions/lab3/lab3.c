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
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

char isNorthernHemisphere(double);
char isSouthernHemisphere(double);
double localDistanceKm(double, double, double, double);
double distanceKm(double, double, double, double);

int main(void)
{
	double latitudeX, longitudeX, latitudeY, longitudeY, distance;
	char Hemisphere = 'f';

	//printf("Enter the latitude and longitude, separated by a comma:  \n");
	//scanf("%lf,%lf", &latitude, &longitude);

	latitudeX = 22.971177;
	longitudeX = -43.182543;
	
	if (isNorthernHemisphere(latitudeX) == 'n') // check if the coordinates are in the northern hemisphere
	{
		Hemisphere = 'n';
	}
	else if (isSouthernHemisphere(latitudeX) == 's') // check if the coordinates are in the southern hemisphere
	{
		Hemisphere = 's';
	}
	else // if the coordinates are neither in the northern nor southern hemispheres, set as the equator
	{
		Hemisphere = 'e';
	}

	distance = localDistanceKm(latitudeX, longitudeX, latitudeY, longitudeY);

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
	// Convert the given latitudes and longitudes from degrees into radians

	// Calculate delta-Y as 111.3 * | latitudeX - latitudeY |

	// Calculate delta-X as 111.3 * cos((latitudeX + latitudeY) / 2) * | longitudeX - longitudeY |

	// Calculate the distance between the two points as square root((delta-X**2 + delta-Y**2))
}