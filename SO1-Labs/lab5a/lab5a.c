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

int getWaypointNumber(void);
void getCoordinates(double *latitudes, double *longitudes, int waypointNumber);
void clearBuffer(void);
int chkDigit(int digit);
int chkFloat(char* string, int flag);
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
	while (1)
	{
		if ((scanf("%d", &input) == 1) && (input >= 0))
			return input;
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
		while (1)
		{
			scanf("%lf %lf", latitude, longitude);
			clearBuffer();

			if (((flag = chkFloat(inputOne, 1)) != 0) && ((flag = chkFloat(inputTwo, 2)) != 0))
			{
				printf("Invalid input (expected \"<latitude> <longitude>\": %s %s\nTry again : ", inputOne, inputTwo);
				continue;
			}
			else if (((flag = chkFloat(inputOne, 1)) != 0) || ((flag = chkFloat(inputTwo, 2)) != 0))
			{
				printf("Invalid input (expected \"<latitude> <longitude>\": %s\nTry again : ", (flag == 1) ? inputOne : inputTwo);
				continue;
			}

			latArr[i] = atof(inputOne); // Convert string into double
			longArr[i] = atof(inputTwo);
			// Check that latitude coordinate is between +90 & -90 degrees and longitude coordinate is between + 180 & -180 degrees
			if (!(latArr[i] >= -90. && latArr[i] <= 90.))
				printf("Invalid input (expected \"<latitude> <longitude>\": %s\nTry again : ", inputOne);
			else if (!(longArr[i] >= -180. && longArr[i] <= 180.))
				printf("Invalid input (expected \"<latitude> <longitude>\": %s\nTry again : ", inputTwo);
			else
				break;
		}
	}
}

void clearBuffer(void)
{
	while (getchar() != '\n')
		continue;
}

void printfBuffer(void)
{

}

int chkFloat(char* string, int arrIdx)
{
	int counter = 0;
	int flag = 0;

	while (string[counter] != '\0')
	{
		if (!(string[0] == '-' || string[counter] == '.' || chkDigit(string[counter]))) // If there is a character, break
		{
			flag = arrIdx;
			break;
		}
		counter++;
	}

	return flag;
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