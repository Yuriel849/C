#include <math.h>

// External variable
const double PI = 3.14159265358979323846;

// External function
void toPolarCoords(double x, double y, double* r, double* phi)
{
	*r = sqrt(x * x + y * y);
	*phi = atan2(y, x);
}