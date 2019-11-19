void minMax(int*, int*, int*, int);

int main(void)
{
	int a[] = { 42, 7, 4, 52, 101, 501, 666, -34, 5 };
	int size = sizeof a / sizeof a[0];
	int minimum, maximum;

	minMax(a, &minimum, &maximum, size);

	printf("Data is in the range [%d, %d].\n", minimum, maximum);

	getchar();
	return 0;
}

void minMax(int *a, int *minimum, int *maximum, int size)
{
	*minimum = *a;
	*maximum = *a;

	for (int i = 1; i < size; i++)
	{
		if (*(a + 1) > *maximum)
			*maximum = *(a + 1);
		else if (*(a + 1) < *minimum)
			*minimum = *(a + 1);
	}
}