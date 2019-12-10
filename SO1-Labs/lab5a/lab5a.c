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

int getWaypntNumber(void);
void getCoordinates(double *latArr, double *longArr, int waypntNumber);
void clearBuffer(void);
int chkDigit(int digit);
double getTotalDistance(double *latArr, double *longArr, int waypntNumber);
double distanceKm(double latitudeX, double longitudeX, double latitudeY, double longitudeY);

int main(void)
{
	int waypntNumber, pointerBytes, dataBytes; // Number of waypoints, number of bytes for pointers, number of bytes for each array of latitudes and longitudes
	double **coordArr, *latArr, *longArr;	   // 1-D arrays for latitudes and longitudes

	waypntNumber = getWaypntNumber(); // Get the number of waypoints from the user

	pointerBytes = 2 * sizeof(double *);
	dataBytes = 2 * waypntNumber * sizeof(double);
	if((coordArr = (double **)malloc(pointerBytes + dataBytes)) == NULL)
		exit(EXIT_FAILURE);

	latArr = (double *)(coordArr + 2);
	longArr = latArr + waypntNumber;

	getCoordinates(latArr, longArr, waypntNumber); // Get "waypntNumber" number of pairs of geographic coordinates

	printf("\nBy taking this route you will travel %.1f km.", getTotalDistance(latArr, longArr, waypntNumber));

	free(coordArr); // Free memory

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
		clearBuffer();
		strLength = strlen(inputOne); // Get length to know if input is one or two characters long
		if ((strLength == 1 && chkDigit(inputOne[0])) || (chkDigit(inputOne[0]) && chkDigit(inputOne[1])))
			return atoi(inputOne); // Convert string into integer
		printf("Try again (expected number >= 0) : ");
	}
}

void getCoordinates(double *latArr, double *longArr, int waypntNumber)
{
	char inputOne[256], inputTwo[256];	// Receive user input as strings
	int counter = 0;						// Length of strings
	int flagContinue = 0;				// Flag variable

	printf("\nEnter waypoints as \"<latitudes> <longitude>\" : \n");
	for (int i = 0; i < waypntNumber; i++)
	{
		printf("Waypoint %d : ", i + 1);
		while (1)
		{
			scanf("%s %s", inputOne, inputTwo);
			clearBuffer();

			while (inputTwo[counter] != '\0')
			{
				if (!(inputTwo[0] == '-' || inputTwo[counter] == '.' || chkDigit(inputTwo[counter]))) // If there is a character, break
				{
					flagContinue = 2;
					break;
				}
				counter++;
			}
			counter = 0;
			while (inputOne[counter] != '\0')
			{
				if (!(inputOne[0] == '-' || inputOne[counter] == '.' || chkDigit(inputOne[counter]))) // If there is a character, break
				{
					flagContinue = 1;
					break;
				}
				counter++;
			}
			counter = 0;

			if (flagContinue != 0)
			{
				printf("Invalid input (expected \"<latitude> <longitude>\": %s\nTry again : ", (flagContinue == 1) ? inputOne : inputTwo);
				flagContinue = 0;
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

int chkDigit(int digit)
{
	int flag = 0;
	
	if(digit == '0' || digit == '1' || digit == '2' || digit == '3' || digit == '4' ||
	   digit == '5' || digit == '6' || digit == '7' || digit == '8' || digit == '9')
		flag = 1;

	return flag;
}

double getTotalDistance(double *latArr, double *longArr, int waypntNumber)
{
	double totalDistance = 0.0;
	
	for (int i = 1; i < waypntNumber; i++)
		totalDistance += distanceKm(latArr[i - 1], longArr[i - 1], latArr[i], longArr[i]);

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