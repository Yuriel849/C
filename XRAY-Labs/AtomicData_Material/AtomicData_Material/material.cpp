/*
 * Filename: atomicData.cpp
 * Author: Myungjun Kim
 * Version: 1.0
 * Date: 31.12.2021
 * Description: Source code file for the cMaterial class.
 */

#include "material.h"
#include "atomicData.h"

using namespace std;

//===========================================================================================================================================
cMaterial::cMaterial() {
	clear();
}

//===========================================================================================================================================
cMaterial::cMaterial(const cMaterial& material) {
	Z = material.Z;
	fraction = material.fraction;
	density = material.density;
	name = material.name;
}

//===========================================================================================================================================
void cMaterial::clear() {
	name = "new material";
	density = 1.0;
	Z.clear();
	fraction.clear();
}

//===========================================================================================================================================
void cMaterial::setName(const std::string& newName) {
	name = newName;
}

//===========================================================================================================================================
const std::string& cMaterial::getName() {
	return name;
}

//===========================================================================================================================================
void cMaterial::addElement(unsigned newZ, double newFraction) {
	Z.push_back(newZ);
	fraction.push_back(newFraction);
}

//===========================================================================================================================================
unsigned cMaterial::getNoOfElements() {
	return Z.size();
}

//===========================================================================================================================================
unsigned cMaterial::getAtomicNumber(unsigned i) {
	return Z.at(i);
}

//===========================================================================================================================================
double cMaterial::getFraction(unsigned i) {
	return fraction.at(i);
}

//===========================================================================================================================================
void cMaterial::setDensity(double newDensity) {
	density = newDensity;
}

//===========================================================================================================================================
double cMaterial::getDensity() {
	return density;
}

//===========================================================================================================================================
/*
 * getAttCoeff(energy)
 *	Evaulate the total attenuation coefficient.
 *	Reads the raw cross section data using the base class cAtomicData
	and evaluates the attenuation cross section according to the given fractions-by-number and density.
 */
double cMaterial::getAttCoeff(double energy) {
	cAtomicData atomic;
	atomic.prepare();

	double avogadro = 6.022140857 * pow(10, 23);
	double numerator = 0.0;
	double denominator = 0.0;
	
	for (unsigned i = 0; i < Z.size(); i++) {
		numerator += atomic.getTotalCrossSection(Z[i], energy) * fraction[i];
		denominator += atomic.getStdAtomicWeight(Z[i]) * fraction[i];
	}

	return density * avogadro * (numerator / denominator);
}

//===========================================================================================================================================
/*
 * getAttSpec(spec, minEnergy, tubeVoltage, energySteps)
 *	Divides the energy interval of "minEnergy" <= interval < "tubeVoltage" into "energySteps"-sized equal steps.
 *	The attenuation spectrum is evaluated for each energy and stored in "spec".
 *	The contents of "spec" are deleted and the new attenuation coefficients replace the previous contents.
 */
void cMaterial::getAttSpec(std::vector<double>& spec, double minEnergy, double tubeVoltage, unsigned energySteps) {
	spec.clear();
	for (double i = minEnergy; i < tubeVoltage; i += energySteps)
		spec.push_back(getAttCoeff(i));
}

//===========================================================================================================================================
/*
 * getMeanFreePath(energy)
 *	Returns the reciprocal of the attenuation coefficient.
 */
double cMaterial::getMeanFreePath(double energy) {
	return 1 / getAttCoeff(energy);
}
