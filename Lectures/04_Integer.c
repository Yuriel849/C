#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <limits.h>
#include <math.h>

int IDT_main()
{
	unsigned short explode = 0; // unsigned short has range of 0 ~ 65535
	printf("%hu\n", explode);

	explode = explode - 1;
	printf("%hu\n", explode); // Underflow: Going down from "0" results in the largest number (65535) in the range of unsigned short

	explode = explode + 2;
	printf("%hu\n", explode); // Overflow: Going up from "65535" results in the smallest number (0) in the range of unsigned short

	// Typically when under-/overflow occurs with integer numbers, the integers wrap around

	getchar();
	return 0;
}