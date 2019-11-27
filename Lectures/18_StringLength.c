#include <stdio.h>
#include <stdlib.h>

int length(char a[]);

int strLength_main(void)
{
	char a[] = "123456789";

	printf("Length = %d\n", length(a));

	getchar();
	return 0;
}

int length(char a[])
{
	int index = 0;

	while (a[index++] != '\0');

	return index - 1; // because index is incremented even when a[index] == '\0'
}