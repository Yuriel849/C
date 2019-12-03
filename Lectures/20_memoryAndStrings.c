#include <stdio.h>
#include <stdlib.h>

int size(char* toClone);
char *cloneString(char* toClone);

int memoryStrings_ain(void)
{
	char* oldLady = "Watch it! I am crossing the road, stupid";
	char* cloned = cloneString(oldLady);

	if (cloned != NULL)
	{
		printf("%s\n%s", oldLady, cloned);
		free(cloned);
	}

	getchar();
	return 0;
}

int size(const char *toClone)
{
	int i = 0;

	while (toClone[i] != '\0')
		i++;

	return i;
}

char* cloneString(char* toClone)
{
	int length = size(toClone); // Determine size of the string
	char* cloned = (char *)malloc((length + 1) * sizeof(char)); // Allocate memory

	if (cloned == NULL) // Check if memory allocation was successful
		exit(EXIT_FAILURE);

	for (int i = 0; i < length; i++) // Copy a string into another string
	{
		cloned[i] = toClone[i];
		cloned[length] = '\0'; // Add the end-of-string to the copied string
	}

	return cloned;
}
