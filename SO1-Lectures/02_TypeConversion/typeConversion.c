/* 02.10.2019 In-Class Exercise */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

signed main() // The datatype "int" == "signed" == "signed int" --> NO DIFFERENCE, MERELY MAKES SIGNED INTERPRETATION EXPLICIT
{
	float tempF, tempC;
	printf("Please enter the current temperature in Fahrenheit: ");
	scanf("%f", &tempF);
	getchar(); // w/o this, the getchar() at the end removes the "enter" key from using scanf and the program returns "0" and terminates

	tempC = (tempF - 32) * 5 / 9;
	printf("The current temperature in Celsius is %.2f C", tempC);
	getchar();

	return 0;
}

/* signed/unsigned long long is new from ISO C99, so the compiler MAY not recognize it
	otherwise, all integer datatypes can be used anywhere and anytime

	which datatype to choose?
		1. consider the size of the data you are expecting to be used
		2. memory concerns (application may not have a lot of spare memory space)
		3. speed of processing (unnecessarily large datatypes may slow down the speed of processing)
			int is typically 1 machine word in length (something longer may not be 1 machine word in length, thus taking longer for the computer to process)
 */