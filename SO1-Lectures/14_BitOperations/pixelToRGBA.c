/* 4 chars for RGBA values, combine the 4 chars into one unsigned int and store in an array, and decompose in reverse */

#define _CRT_SECURE_NO_DEPRECATE_
#include <stdio.h>
#include <stdlib.h>

typedef unsigned uint32; // Create a new type for a 32-bit unsigned integer
uint32 valuesToPixel(unsigned char, unsigned char, unsigned char, unsigned char);
void pixelToValues(uint32, unsigned char*, unsigned char*, unsigned char*, unsigned char*);

int main(void)
{
	unsigned char red = 11, green = 21, blue = 61, alpha = 3;
	uint32 pixel;

	pixel = valuesToPixel(red, green, blue, alpha);

	printf("DECIMAL : %u, HEXADECIMAL : %X\n", pixel, pixel);

	red = green = blue = alpha = 0;
	pixelToValues(pixel, &red, &green, &blue, &alpha);

	printf("RGBA : (%u, %u, %u, %u)\n", red, green, blue, alpha);

	pixel |= 0x04000000;

	red = green = blue = alpha = 0;
	pixelToValues(pixel, &red, &green, &blue, &alpha);

	printf("RGBA : (%u, %u, %u, %u)\n", red, green, blue, alpha);

	getchar();
	return 0;
}

uint32 valuesToPixel(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	uint32 pixel = 0;

	pixel |= (uint32)red << 24;
	pixel |= (uint32)green << 16;
	pixel |= (uint32)blue << 8;
	pixel |= (uint32)alpha;

	return pixel;
}

void pixelToValues(uint32 pixel, unsigned char* red, unsigned char* green, unsigned char* blue, unsigned char* alpha)
{
	unsigned char mask = 0xff; // 0xff(16) == 255(10) == 11111111(2)
	*red = (unsigned char)((pixel >> 24) & mask);
	*green = (unsigned char)((pixel >> 16) & mask);
	*blue = (unsigned char)((pixel >> 8) & mask);
	*alpha = (unsigned char)(pixel & mask);
}