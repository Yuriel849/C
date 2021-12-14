#include "particle.h"
#include <math.h>

using namespace std;

cParticle::cParticle(const cParticle& original) {
	for (unsigned i = 0; i < 3; i++) {
		pos[i] = original.pos[i];
		dir[i] = original.dir[i];
	}
}

void cParticle::getPosition(double& x, double& y, double& z) const {
	x = pos[0];
	y = pos[1];
	z = pos[2];
}

void cParticle::getDirection(double& x, double& y, double& z) const {
	x = dir[0];
	y = dir[1];
	z = dir[2];
}

void cParticle::setPosition(double x, double y, double z) {
	pos[0] = x;
	pos[1] = y;
	pos[2] = z;
}

void cParticle::setDirection(double x, double y, double z) {
	dir[0] = x;
	dir[1] = y;
	dir[2] = z;
}

void cParticle::getPosition(double p[3]) const {
	p[0] = pos[0];
	p[1] = pos[1];
	p[2] = pos[2];
}

void cParticle::getDirection(double d[3]) const {
	d[0] = dir[0];
	d[1] = dir[1];
	d[2] = dir[2];
}

void cParticle::setPosition(double p[3]) {
	pos[0] = p[0];
	pos[1] = p[1];
	pos[2] = p[2];
}

void cParticle::setDirection(double d[3]) {
	dir[0] = d[0];
	dir[1] = d[1];
	dir[2] = d[2];
}

double cParticle::minDist2Origin() const {
	return minDist2Point(0, 0, 0);
}

double cParticle::minDist2Point(double x, double y, double z) const {
	// (ux*X + uy*Y + uz*Z) = d
	// Use dir as normal vector (ux, uy, uz) and pos array as (x0, y0, z0)
	// Calculate distance to the origin as d with sqrt of sum of squared differences
	// Plug in ((ux * lambda + x0), (uy * lambda + y0), (uz * lambda + z0)) as (X, Y, Z)
	// Resolve for lambda and calculate (X, Y, Z)
	// (X, Y, Z) represents point of perpendicular intersection between line and plane
	// Calculate minimum distance between the intersection point to point (x, y, z) from function parameters

	double d = 0;
	if ((x != 0) || (y != 0) || (z != 0)) d = sqrt((x * x) + (y * y) + (z * z));
	double lambda = (d - ((dir[0] * pos[0]) + (dir[1] * pos[1]) + (dir[2] * pos[2]))) / ((dir[0] * dir[0]) + (dir[1] * dir[1]) + (dir[2] * dir[2]));
	double intersect[3] = { (dir[0] * lambda + pos[0]), (dir[1] * lambda + pos[1]), (dir[2] * lambda + pos[2]) };
	return sqrt(((intersect[0] - x) * (intersect[0] - x)) + ((intersect[1] - y) * (intersect[1] - y)) + ((intersect[2] - z) * (intersect[2] - z)));
}

double cParticle::minDist2Point(double p[3]) const {
	return minDist2Point(p[0], p[1], p[2]);
}
