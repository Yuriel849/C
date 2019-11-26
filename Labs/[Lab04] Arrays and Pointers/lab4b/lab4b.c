/* Author	   : Myungjun Kim
   Contents    : Determine which of the two locations are furthest from each other
   Instructions:
	  a) Store the locations¡¯ names in an array of strings (e.g., char *names[] = { ... };).
	  b) Store the geographic coordinates in a 7 ¡¿ 2 matrix. Each row contains the latitude and longitude of a location.
	  c) Write a function that receives, amongst others, a Mx2 matrix of coordinates as parameter.
		 The function shall determine which two locations in the matrix have the largest distance.
		 It returns the maximum distance as well as the row indices of the corresponding locations.
	  d) Print the locations¡¯ names and distance to the console.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <corecrt_math_defines.h>

void maximumDistance(const double latLong[][2], int size, double* distance, int* rowA, int* rowB);
double distanceKm(double, double, double, double);

int main(void)
{
	double distance = 0.0;
	int rowA, rowB, size;

	char* names[] = {
		"HAW Hamburg"
		, "Eiffel Tower"
		, "Palma de Mallorca"
		, "Las Vegas"
		, "Copacabana"
		, "Waikiki Beach"
		, "Surfer's Paradise"
	};

	double coordinates[][2] = {
		{53.557078, 10.023109}
		, {48.858363, 2.294481}
		, {39.562553, 2.661947}
		, {36.156214, -115.148736}
		, {-22.971177, -43.182543}
		, {21.281004, -157.837456}
		, {-28.002695, 153.431781}
	};

	size = sizeof coordinates / sizeof coordinates[0];

	maximumDistance(coordinates, size, &distance, &rowA, &rowB);
	printf("%s and %s have the greatest distance between them (%.2lf KM)\n", names[rowA], names[rowB], distance);
	printf("That's pretty far; you had better get a flight instead of trying to walk and swim that distance.");

	getchar();
	return 0;
}

void maximumDistance(const double latLong[][2], int size, double* distance, int* rowA, int* rowB)
{
	double tempDistance;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (!(i < j)) // == (i == j || i > j)
				continue;

			tempDistance = distanceKm(latLong[i][0], latLong[i][1], latLong[j][0], latLong[j][1]);

			if (*distance < tempDistance)
			{
				*distance = tempDistance;
				*rowA = i;
				*rowB = j;
			}
		}
	}
}

double distanceKm(double latitudeX, double longitudeX, double latitudeY, double longitudeY)
{
	double sinLatX, sinLatY, cosLatX, cosLatY, cosLong;

	// Convert degrees into radians
	sinLatX = sin(latitudeX * M_PI / 180.0);
	sinLatY = sin(latitudeY * M_PI / 180.0);
	cosLatX = cos(latitudeX * M_PI / 180.0);
	cosLatY = cos(latitudeY * M_PI / 180.0);
	cosLong = cos((longitudeY - longitudeX) * M_PI / 180.0);

	// Calculate and return the distance between two points
	return 6378.388 * acos((sinLatX * sinLatY) + (cosLatX * cosLatY * cosLong));
}