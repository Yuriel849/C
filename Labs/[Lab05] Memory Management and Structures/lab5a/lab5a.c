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
		 Make sure to free dynamically allocated memory before the application exits
 */

#define _CRT_SECURE_NO_DEPRECATE	// to use scanf() without warnings
#define _USE_MATH_DEFINES			// to use math constants (i.e. PI)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double distanceKm(double latitudeX, double longitudeX, double latitudeY, double longitudeY);

int main(void)
{
	int waypointNumber; // Variable for the number of waypoints
	double* waypntArr; // 1-D array to hold arrays
	int totalDistance = 0; // Variable for the total distance between all waypoints

	// User input: Request the number of waypoints
	printf("Enter number of waypoints : ");
	// Check that the user entered a number and nothing else (i.e. text)
	while (scanf("%d", &waypointNumber) != 1)
		while (getchar() != '\0')
			continue;
		printf("Try again (expected number >= 0) : ");
	// Create a 1-D array with as many elements as the number of waypoints
	waypntArr = (double*)calloc(waypointNumber, sizeof(double*));
	if (waypntArr == NULL)
		exit(EXIT_FAILURE);
	// User input: Request as many pairs of geographic coordinates as the number of waypoints
	printf("Enter waypoints as \"<latitudes> <longitude>\" : \n");
	for (int i = 0; i < waypointNumber; i++)
	{
		double* coordArr[2] = { 0, 0 };
		printf("Waypoint %d : ", i);
		while (scanf("%f %f", coordArr[0], coordArr[1]) != 1)
			printf("Invalid input (expected \"<latitude> <longitude>\": \nTry again : ");
	}


	// Check that both coordinates are proper floating-point numbers and nothing else (i.e. text)
	// Create a 1-D array to hold a pair of coordinates and assign to each element of the first array
	// Run a loop to call a function determine the distance between two sets of coordinates, and sum up all distances
	// Print the total distance between the coordinates
	// Free memory allocated to arrays holding waypoint coordinates

	getchar();
	return 0;
}

// REUSE CODE (Lab03 & Lab04) -- Determine the distance between two pairs of coordinates
double distanceKm(double latitudeX, double longitudeX, double latitudeY, double longitudeY)
{
	double sinLatX, sinLatY, cosLatX, cosLatY, cosLong;

	sinLatX = sin(latitudeX * M_PI / 180.0); // Convert degrees into radians
	sinLatY = sin(latitudeY * M_PI / 180.0);
	cosLatX = cos(latitudeX * M_PI / 180.0);
	cosLatY = cos(latitudeY * M_PI / 180.0);
	cosLong = cos((longitudeY - longitudeX) * M_PI / 180.0);

	return 6378.388 * acos((sinLatX * sinLatY) + (cosLatX * cosLatY * cosLong)); // Calculate & return distance between two points
}