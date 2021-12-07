#include "particle.h"

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
