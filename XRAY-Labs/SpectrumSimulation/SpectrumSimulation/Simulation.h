/*
 * Filename: atomicData.h
 * Author: Myungjun Kim
 * Version: 1.0
 * Date: 31.12.2021
 * Description: Header file for the cAtomicData class.
 */

 // Ensures this file is compiled only once per .cpp file.
#pragma once

#include "spectrum.h"

class cSimulation {
private:
	double tubePos[3]; // Position of x-ray tube (x, y, z) in meters
	double tubeVoltage; // Tube voltage in kV
	double spherePos[3]; // Position of sphere (x, y, z) in meters
	double sphereRadius; // Radius of sphere in meters
	double pixelSize;
	cSpectrum xRayTube;
	cSpectrum attCoeff;
public:
	cSimulation();
	~cSimulation();
	void setTubePosition(double x, double y, double z);
	void setTubeVoltage(double voltage);
	void setSpherePosition(double x, double y, double z);
	void setSphereRadius(double radius);
	void setPixelSize(double size);
	prepare();
	simulate();
};