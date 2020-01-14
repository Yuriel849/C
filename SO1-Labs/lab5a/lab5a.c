/* Author	   : Myungjun Kim
   Contents    : Virtually plan a trip with double arrays
   Instructions:
	  Customer requirements :
		 Users shall enter the number of waypoints (i.e. place of departure and the destinations).
		 Users shall enter the geographic coordinates of all waypoints.
		 After correct user input the program shall print the overall length of the route to the console.
	  Technical requirements :
		 In case of invalid input, the application will repeat the request until users enter correct data.
		 Dynamically allocate 1-D arrays to hold the latitudes and the longitudes of the waypoints.
		 Make sure to free dynamically allocated memory before the application exits.
 */

#define _CRT_SECURE_NO_DEPRECATE	// To use scanf() without warnings
#define _USE_MATH_DEFINES			// To use math constants (i.e. PI)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>					// To use sin(), cos(), acos()
#include <string.h>					// To use strlen()

enum {
	FALSE, TRUE
};

int getWaypointNumber(void);
void getCoordinates(double *latitudes, double *longitudes, int waypointNumber);
void clearBuffer(void);
void printBuffer(void);
double getTotalDistance(const double *latitudes, const double *longitudes, int waypointNumber);
double distanceKm(double latitudeX, double longitudeX, double latitudeY, double longitudeY);

int main(void)
{
	int waypointNumber, pointerBytes, dataBytes; // Nr. of waypoints, nr. of bytes for pointers, nr. of bytes for each array
	double **coordinates, *latitudes, *longitudes;	   // 1-D arrays for latitudes and longitudes

	waypointNumber = getWaypointNumber(); // Get the number of waypoints from the user

	pointerBytes = 2 * sizeof(double *);
	dataBytes = 2 * waypointNumber * sizeof(double);
	if ((coordinates = (double **)malloc(pointerBytes + dataBytes)) == NULL)
		exit(EXIT_FAILURE);

	latitudes = (double *)(coordinates + 2);
	longitudes = latitudes + waypointNumber;

	getCoordinates(latitudes, longitudes, waypointNumber); // Get "waypointNumber" pairs of geographic coordinates from the user

	printf("\nBy taking this route you will travel %.1f km.", getTotalDistance(latitudes, longitudes, waypointNumber));

	free(coordinates); // Free memory

	getchar();
	return 0;
}

int getWaypointNumber(void)
{
	int input;

	printf("Enter number of waypoints : ");
	while (TRUE)
	{
		if ((scanf("%d", &input) == 1) && (input >= 0))
		{
			clearBuffer();
			return input;
		}
		clearBuffer();
		printf("Try again (expected number >= 0) : ");
	}
}

void getCoordinates(double *latitudes, double *longitudes, int waypointNumber)
{
	double latitude, longitude;

	printf("\nEnter waypoints as \"<latitudes> <longitude>\" : \n");
	for (int i = 0; i < waypointNumber; i++)
	{
		printf("Waypoint %d : ", i + 1);
		while (TRUE)
		{
			scanf("%lf %lf", &latitude, &longitude);

			if ((latitude >= -90. && latitude <= 90.) && (longitude >= -180. && longitude <= 180.))
			{
				latitudes[i] = latitude;
				longitudes[i] = longitude;
				clearBuffer();
				break;
			}
			else
			{
				printf("Invalid input (expected \"<latitude> <longitude>\": ");
				printBuffer();
				printf("\nTry again : ");
				clearBuffer();
			}
		}
	}
}

void clearBuffer(void)
{
	while (getchar() != '\n')
		continue;
}

void printBuffer(void)
{
	char input;

	while ((input = getchar()) != '\n')
		fputc(input, stdout);
}

double getTotalDistance(const double *latitudes, const double *longitudes, int waypointNumber)
{
	double totalDistance = 0.0;

	for (int i = 1; i < waypointNumber; i++)
		totalDistance += distanceKm(latitudes[i - 1], longitudes[i - 1], latitudes[i], longitudes[i]);

	return totalDistance;
}

// REUSE CODE (Lab03 & Lab04) -- Determine the distance between two pairs of coordinates
double distanceKm(double latitudeX, double longitudeX, double latitudeY, double longitudeY)
{
	double sinLatX, sinLatY, cosLatX, cosLatY, cosLong, PI_over_180 = M_PI / 180.0; // Convert degrees into radians

	sinLatX = sin(latitudeX * PI_over_180);
	sinLatY = sin(latitudeY * PI_over_180);
	cosLatX = cos(latitudeX * PI_over_180);
	cosLatY = cos(latitudeY * PI_over_180);
	cosLong = cos((longitudeY - longitudeX) * PI_over_180);

	return 6378.388 * acos((sinLatX * sinLatY) + (cosLatX * cosLatY * cosLong)); // Calculate & return distance between two points
}