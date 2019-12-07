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
#include <ctype.h>
#include <string.h>

double distanceKm(double latitudeX, double longitudeX, double latitudeY, double longitudeY);


int main(void)
{
	char inputOne[6], inputTwo[6];// Variables to receive user input as strings, to then be parsed
	int waypntNumber; // Variable for the number of waypoints
	double *latArr, *longArr; // 1-D arrays to hold latitudes and longitudes
	double totalDistance = 0.0; // Variable for the total distance between all waypoints
	int strLength;

	// User input: Request the number of waypoints
	printf("Enter number of waypoints : ");
	// Check that the user enters a number and nothing else (i.e. text)
	while (1) // Validation of waypoint number input
	{
		scanf("%2s", inputOne); // Reads a string which is maximum two characters long
		while (getchar() != '\n') // Clears the input buffer
			continue;
		strLength = strlen(inputOne); // Gets length of the input string, to know if it is one or two characters long
		if (strLength == 1 && isdigit(inputOne[0])) // If one character long and that is a digit, break
		{
			waypntNumber = inputOne[0] - '0';
			break;
		}
		else if (isdigit(inputOne[0]) && isdigit(inputOne[1])) // If first and second characters are both digits, break
		{
			waypntNumber = (inputOne[0] - '0') * 10 + (inputOne[1] - '0');
			break;
		}

		printf("Try again (expected number >= 0) : ");
	}


	// Create two 1-D arrays with as many elements as the number of waypoints
	latArr = (double *)calloc(waypntNumber, sizeof(double));
	longArr = (double *)calloc(waypntNumber, sizeof(double));
	if (latArr == NULL || longArr == NULL)
		exit(EXIT_FAILURE);
	// User input: Request as many pairs of geographic coordinates as the number of waypoints
	printf("Enter waypoints as \"<latitudes> <longitude>\" : \n");
	for (int i = 0; i < waypntNumber; i++)
	{
		printf("Waypoint %d : ", i);
		// Check that both coordinates are proper floating-point numbers between +90 & -90 degrees for latitude and +180 & -180 degrees for longitude, and nothing else (i.e. text)
		while (1)
		{
			scanf("%5s %5s", inputOne, inputTwo); // Reads two string which are each maximum five characters long (excluding \0)
			while (getchar() != '\n') // Clears the input buffer
				continue;

			strLength = strlen(inputOne); // Gets length of the input string, to know if it is one or two characters long
			if (strLength == 1 && isdigit(inputOne[0])) // If one character long and that is a digit, break
			{
				waypntNumber = inputOne[0] - '0';
				break;
			}
			else if (isdigit(inputOne[0]) && isdigit(inputOne[1])) // If first and second characters are both digits, break
			{
				waypntNumber = (inputOne[0] - '0') * 10 + (inputOne[1] - '0');
				break;
			}

			printf("Invalid input (expected \"<latitude> <longitude>\": %s\ntry again : ", inputOne);
		}
	}

	// Run a loop to call a function determine the distance between two sets of coordinates, and sum up all distances
	for (int i = 1; i < waypntNumber; i++)
		totalDistance += distanceKm(latArr[i - 1], longArr[i - 1], latArr[i], longArr[i]);

	// Print the total distance between the coordinates
	printf("By taking this route you will travel %f km.", totalDistance);

	// Free memory allocated to arrays holding waypoint coordinates
	free(latArr);
	free(longArr);

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