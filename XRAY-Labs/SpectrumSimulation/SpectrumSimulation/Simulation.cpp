#include "Simulation.h"

void cSimulation::setTubePosition(double x, double y, double z) {
	tubePos[0] = x;
	tubePos[1] = y;
	tubePos[2] = z;
}

void cSimulation::setTubeVoltage(double voltage) {
	tubeVoltage = voltage;
}

void cSimulation::setSpherePosition(double x, double y, double z) {
	spherePos[0] = x;
	spherePos[1] = y;
	spherePos[2] = z;
}

void cSimulation::setSphereRadius(double radius) {
	sphereRadius = radius;
}

void cSimulation::setPixelSize(double size) {
	pixelSize = size;
}
