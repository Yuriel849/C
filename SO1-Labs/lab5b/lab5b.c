/* Author	   : Myungjun Kim
   Contents    : Virtually plan a trip with double arrays
   Instructions:
	  Customer requirements :
		 Users shall enter the number of waypoints (i.e. place of departure and the destinations).
		 Users shall enter the geographic coordinates of all waypoints.
		 After correct user input the program shall print the overall length of the route to the console.
	  Technical requirements :
		 In case of invalid input, the application will repeat the request until users enter correct data.
		 Introduce a structure "struct geoCoord" holding the latitude and longitude (not the name) of a single geographic coordinate.
		 Modify "lab5a.c" so that it uses the structure to store the coordinates of the waypoints.
		 (For clarification: The solution shall have the same functionality as "lab5a.c", however, using the data type struct geoCoord.)
 */

#define _CRT_SECURE_NO_DEPRECATE	// to use scanf() without warnings
#define _USE_MATH_DEFINES			// to use math constants (i.e. PI)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

double distanceKm(double latitudeX, double longitudeX, double latitudeY, double longitudeY);
int getWaypntNumber(void);
void getCoordinates(struct geoCoord *coordinates, int waypntNumber);

struct geoCoord {
	double latArr;
	double longArr;
};

int main(void)
{
	int waypntNumber;				// Number of waypoints
	struct geoCoord *coordinates;	// 1-D array to hold geoCoord
	double totalDistance = 0.0;		// Total distance between all waypoints

	waypntNumber = getWaypntNumber();

	// Create 1-D array with as many elements as the number of waypoints
	coordinates = (struct geoCoord *)calloc(waypntNumber, sizeof(struct geoCoord));
	if (coordinates == NULL) // Check if memory allocation was successful
		exit(EXIT_FAILURE);

	getCoordinates(coordinates, waypntNumber);

	for (int i = 1; i < waypntNumber; i++) // Get and sum up distance between two sets of coordinates
		totalDistance += distanceKm(coordinates[i - 1].latArr, coordinates[i - 1].longArr, coordinates[i].latArr, coordinates[i].longArr);

	printf("\nBy taking this route you will travel %.1f km.", totalDistance); // Print the total distance between the coordinates

	free(coordinates); // Free memory allocated to arrays holding waypoint coordinates

	getchar();
	return 0;
}

int getWaypntNumber(void)
{
	char inputOne[3];	// Receive user input as strings
	int strLength;		// Length of strings

	printf("Enter number of waypoints : ");
	while (1)
	{
		scanf("%2s", inputOne); // User input: String which is maximum two characters long
		while (getchar() != '\n') // Clear input buffer
			continue;
		strLength = strlen(inputOne); // Get length to know if input is one or two characters long
		if ((strLength == 1 && isdigit(inputOne[0])) || (isdigit(inputOne[0]) && isdigit(inputOne[1])))
		{
			return atoi(inputOne); // Convert string into integer
		}

		printf("Try again (expected number >= 0) : ");
	}
}

void getCoordinates(struct geoCoord *coordinates, int waypntNumber)
{
	char inputOne[256], inputTwo[256];	// Receive user input as strings
	int strLength;						// Length of strings
	int flagContinue = 0;				// Flag variable

	printf("Enter waypoints as \"<latitudes> <longitude>\" : \n");
	for (int i = 0; i < waypntNumber; i++)
	{
		printf("Waypoint %d : ", i + 1);
		while (1)
		{
			scanf("%s %s", inputOne, inputTwo); // Read two strings which are each maximum five characters long (excluding '\0')
			while (getchar() != '\n') // Clear the input buffer
				continue;
			//printf("CHECK PRINT STRINGS : %s %s\n", inputOne, inputTwo);
			//printf("CHECK PRINT NUMBERS : %f %f\n", atof(inputOne), atof(inputTwo);

			strLength = strlen(inputOne);
			for (int j = 0; j < strLength; j++) // Loop through first input, check there are only numbers or period or dash (for negative numbers)
			{
				if (!(isdigit(inputOne[j]) || inputOne[j] == '.' || inputOne[j] == '-')) // If there is a character, break
				{
					flagContinue = 1;
					break;
				}
			}
			if (flagContinue == 1)
			{
				flagContinue = 0;
				printf("Invalid input (expected \"<latitude> <longitude>\": %s\nTry again : ", inputOne);
				continue;
			}

			strLength = strlen(inputTwo);
			for (int j = 0; j < strLength; j++) // Loop through second input, check there are only numbers or period or dash (for negative numbers)
			{
				if (!(isdigit(inputTwo[j]) || inputTwo[j] == '.' || inputOne[j] == '-')) // If there is a character, break
				{
					flagContinue = 1;
					break;
				}
			}
			if (flagContinue == 1)
			{
				flagContinue = 0;
				printf("Invalid input (expected \"<latitude> <longitude>\": %s\nTry again : ", inputTwo);
				continue;
			}

			coordinates[i].latArr = atof(inputOne); // Convert string into double
			coordinates[i].longArr = atof(inputTwo);
			// Check that latitude coordinate is between +90 & -90 degrees and longitude coordinate is between + 180 & -180 degrees
			if (!(coordinates[i].latArr >= -90. && coordinates[i].latArr <= 90.))
				printf("Invalid input (expected \"<latitude> <longitude>\": %s\nTry again : ", inputOne);
			else if (!(coordinates[i].longArr >= -180. && coordinates[i].longArr <= 180.))
				printf("Invalid input (expected \"<latitude> <longitude>\": %s\nTry again : ", inputTwo);
			else
				break;
		}
	}
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