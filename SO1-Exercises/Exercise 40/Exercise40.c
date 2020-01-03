/* Author	   : Myungjun Kim
   Contents    : Exercise 40.
   Instructions:
      Declare a data type time representing the time of the day in hours, minutes, and seconds.
	  Additionally write and apply following functions:
	     Function isTimeValid() to check, if the data is valid.
			Write and use an enumerated type timeStatus with symbolic constants TIME_OK and TIME_INVALID for the return value.
			The value of TIME_INVALID must correspond to the Boolean false.
		 Function timeFromSec() that accepts the time in seconds elapsed since midnight and returns the corresponding time of type time.
		 Function timePeriod() returning the period (i. e., difference) between two arguments of type time passed to the function.
			The function shall return type time.
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

// Enumeration
typedef enum timeStatus { TIME_INVALID, TIME_OK } timeStatus;

 // Structure
typedef struct {
	int hours;
	int minutes;
	int seconds;
} time;

// Function prototypes
timeStatus isTimeValid(time);
time timeFromSec(int);
time timePeriod(time, time);
int timeToSec(time data);

int main(void)
{
	time testTime[6] = {
		{23, 15, 33},   // Valid time
		{25, 15, 33},   // Invalid hour
		{23, -3, 33},   // Invalid minute
		{23, 15, 7345}, // Invalid second
		{21, 00, 00},   // Start time
		{23, 55, 00},   // End time
	};
	time period = timePeriod(testTime[4], testTime[5]);

	printf("Valid time     : %d\n", isTimeValid(testTime[0]));
	printf("Invalid hour   : %d\n", isTimeValid(testTime[1]));
	printf("Invalid minute : %d\n", isTimeValid(testTime[2]));
	printf("Invalid second : %d\n", isTimeValid(testTime[3]));
	printf("Time difference: %02d:%02d:%02d\n", period.hours, period.minutes, period.seconds);

	getchar();
	return 0;
}

timeStatus isTimeValid(time data)
{
	timeStatus returnValue = TIME_INVALID;

	if ((data.hours >= 0 && data.hours < 24) &&
		(data.minutes >= 0 && data.minutes < 60) &&
		(data.seconds >= 0 && data.seconds < 60))
		returnValue = TIME_OK;

	return returnValue;
}

time timeFromSec(int seconds)
{
	time returnValue;

	if (seconds < 0)
		seconds *= -1;

	returnValue.seconds = seconds % 60;
	returnValue.minutes = seconds / 60 % 60;
	returnValue.hours = seconds / 60 / 60;

	return returnValue;
}

int timeToSec(time data)
{
	return data.seconds + (data.minutes * 60) + (data.hours * 60 * 60);
}

time timePeriod(time startTime, time endTime)
{
	int differenceInSeconds = timeToSec(endTime) - timeToSec(startTime);
	return timeFromSec(differenceInSeconds);
}