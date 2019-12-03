/* DEFINE constants... cannot be treated like external variable,
		one solution would be to put all DEFINEs in one file and include that file
 */

#include <stdio.h>

extern const double PI;
extern void toPolarCoords(double x, double y, double* r, double* phi);

int main(void)
{
	double x = 2.0, y = 3.75; // Input: Cartesian coordinates
	double r, phi; // Result: Polar coordinates
	
	toPolarCoords(x, y, &r, &phi);
	printf("Cartesian: (x, y) = (%.2f, %.2f)\n", x, y);
	printf("Polar : (r, phi) = (%.2f, %.2f * pi)\n", r, phi / PI);

	getchar();
	return 0;
}