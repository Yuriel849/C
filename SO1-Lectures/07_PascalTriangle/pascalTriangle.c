#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int binomial(int k, int n);

int main(void)
{
	int maxN = 6;

	for (int n = 0; n <= maxN; n++)
	{
		for (int k = 0; k <= n; k++)
		{
			printf("%3d", binomial(k, n)); // Would be simple to solve with a two-dimensional array, but we didn't learn it yet so...
		}

		printf("\n");
	}

	getchar();
	return 0;
}

int binomial(int k, int n)
{
	if (k == 0 || k == n)
		return 1;
	else
		return binomial(k - 1, n - 1) + binomial(k, n - 1);
}