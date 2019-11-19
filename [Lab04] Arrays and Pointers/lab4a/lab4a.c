/* Author	   : Myungjun Kim
   Contents    : Determine the overall distance in km of the walk around the block
   Instructions:
	  a) Write a function to determine the distance of a route in km.
		 => Sum the distance between each of the waypoints to determine the total distance.
	  b) Re-use the function distanceKm() from lab 3. Do not modify that function.
		 => Use distanceKm() to determine the distance between two waypoints (using latitudes and longitudes).
	  c) Use two arrays, one to hold the latitudes and one to hold the longitudes of the waypoints.
		 The geographic coordinates are given in Table 6.1.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <corecrt_math_defines.h>

double totalDistance(const double*, const double*, int);
double distanceKm(double, double, double, double);

int main(void)
{
	double distance = 0.0; // total distance
	int size; // size of the array

	double latitude[9] = {
		53.557029
		, 53.557166
		, 53.557274
		, 53.560288
		, 53.561306
		, 53.562015
		, 53.558241
		, 53.557900
		, 53.557203
	};

	double longitude[9] = {
		10.022918
		, 10.021343
		, 10.021343
		, 10.021343
		, 10.021343
		, 10.016568
		, 10.023244
		, 10.022142
		, 10.022632
	};

	size = sizeof latitude / sizeof latitude[0]; // sizeof latitude is 8 bytes * 9 elements = 72
	distance = totalDistance(latitude, longitude, size);
	printf("The total distance travelled during this walk around the block is %.2f km.", distance);

	getchar();
	return 0;
}

// When passing a pointer to an array as a parameter, double *array == double array[]
double totalDistance(const double *arrLat, const double *arrLong, int size)
{
	// *arrLat == arrLat[0] => BECAUSE array = &array[0]
	// sizeof arrLat == sizeof(int) => BECAUSE irrespective of what the datatype being referenced is, the pointer itself is the size of int

	double sum = 0;

	for (int i = 1; i < size; i++)
	{
		// *(a + 1) == a[1] -> The address the pointer is pointing at is increased by 1 * (size of element's datatype)
		sum += distanceKm(*(arrLat + i), *(arrLong + i), *(arrLat + i - 1), *(arrLong + i - 1));
		// THE ABOVE IS EQUAL TO : *distance += distanceKm(arrLat[i], arrLong[i], arrLat[i - 1], arrLong[i - 1]);
	}

	return sum;
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