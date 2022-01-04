/*
 * Filename: atomicData.cpp
 * Author: Myungjun Kim
 * Version: 1.0
 * Date: 31.12.2021
 * Description: Source code file for the cMaterial class.
 */

#include "material.h"
#include "atomicData.h"
#include <iostream>

using namespace std;

//===========================================================================================================================================
/* Constructor of the cMaterial class.
 * Calls "clear()" to delete any preexisting data and reset variables.
 */
cMaterial::cMaterial() {
	clear();
}

//===========================================================================================================================================
/* Copy constructor.
 */
cMaterial::cMaterial(const cMaterial& material) {
	Z = material.Z;
	fraction = material.fraction;
	density = material.density;
	name = material.name;
}

//===========================================================================================================================================
/* Clears preexisting data and resets variables.
 */
void cMaterial::clear() {
	name = "new material";
	density = 1.0;
	Z.clear();
	fraction.clear();
}

//===========================================================================================================================================
/* Sets a new name for this material.
 */
void cMaterial::setName(const std::string& newName) {
	name = newName;
}

//===========================================================================================================================================
/* Returns the name of this material.
 */
const std::string& cMaterial::getName() {
	return name;
}

//===========================================================================================================================================
/* Adds a new element for this material.
 * "newZ" is the atomic number of the new element.
 * "newFraction" is the fraction-by-number of the new element. ex) For water, or H2O, "newFraction" = 2 for H and "newFraction" = 1 for O.
 */
void cMaterial::addElement(unsigned newZ, double newFraction) {
	Z.push_back(newZ);
	fraction.push_back(newFraction);
}

//===========================================================================================================================================
/* Returns the number of elements in this material.
 */
unsigned cMaterial::getNoOfElements() {
	return Z.size();
}

//===========================================================================================================================================
/* Returns the atomic number for the element at the given index "i".
 */
unsigned cMaterial::getAtomicNumber(unsigned i) {
	return Z.at(i);
}

//===========================================================================================================================================
/* Returns the fraction-by-number at the given index "i".
 */
double cMaterial::getFraction(unsigned i) {
	return fraction.at(i);
}

//===========================================================================================================================================
/* Sets a new density for this material.
 */
void cMaterial::setDensity(double newDensity) {
	density = newDensity;
}

//===========================================================================================================================================
/* Returns the density of this material.
 */
double cMaterial::getDensity() {
	return density;
}

//===========================================================================================================================================
/* Evaulate the total attenuation coefficient.
 * Reads the raw cross section data using the base class cAtomicData
   and evaluates the attenuation cross section according to the given fractions-by-number and density.
 */
double cMaterial::getAttCoeff(double energy) {
	cAtomicData atomic; // Instance of the cAtomicData class and the source of atomic weights and cross sections in barn for elements.
	atomic.prepare();
	double avogadro = 6.022140857 * pow(10, 23); // Avogadro constant.
	double numerator = 0.0;						 // Numerator for calculating the attenuation coefficient.
	double denominator = 0.0;					 // Denominator for calculating the attenuation coefficient.
	
	// Loop through the elements and sum up the numerators and denominators for calculating the attenuation coefficient.
	for (unsigned i = 0; i < Z.size(); i++) {
		numerator += atomic.getTotalCrossSection(Z[i], energy) * fraction[i];
		denominator += atomic.getStdAtomicWeight(Z[i]) * fraction[i];
	}

	return density * avogadro * (numerator / denominator);
}

//===========================================================================================================================================
/* Divides the energy interval of "minEnergy" <= interval < "tubeVoltage" into "energySteps"-sized equal steps.
 * The attenuation spectrum is evaluated for each energy and stored in "spec".
 * The contents of "spec" are deleted and the new attenuation coefficients replace the previous contents.
 */
void cMaterial::getAttSpec(std::vector<double>& spec, double minEnergy, double tubeVoltage, unsigned energySteps) {
	spec.clear();
	for (double i = minEnergy; i < tubeVoltage; i += energySteps)
		spec.push_back(getAttCoeff(i));
}

//===========================================================================================================================================
/* Returns the reciprocal of the attenuation coefficient.
 */
double cMaterial::getMeanFreePath(double energy) {
	return 1 / getAttCoeff(energy);
}