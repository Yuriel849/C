/* Author	   : Myungjun Kim
   Contents    : Calculate the hemisphere
   Instructions: 1. Hemispheres
					a) Implement a function isNorthernHemisphere() that returns a logical true only if the geographic location passed to the function is on the northern hemisphere
					b) Implement a function isSouthernHemisphere() accordingly.
					c) Write a program that uses some test coordinates to verify the correct return values.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

char isNorthernHemisphere(double);
char isSouthernHemisphere(double);

int main(void)
{
	double latitude, longitude;
	char Hemisphere = 'f';

	//printf("Enter the latitude and longitude, separated by a comma:  \n");
	//scanf("%lf,%lf", &latitude, &longitude);

	latitude = 22.971177;
	longitude = -43.182543;
	
	if (isNorthernHemisphere(latitude) == 'n')
	{
		Hemisphere = 'n';
	}
	else if (isSouthernHemisphere(latitude) == 's')
	{
		Hemisphere = 's';
	}
	else
	{
		Hemisphere = 'e';
	}

	printf("%c", Hemisphere);

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