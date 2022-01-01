/*
 * Filename: atomicData.cpp
 * Author: Myungjun Kim
 * Version: 1.0
 * Date: 31.12.2021
 * Description: Source code file for the cAtomicData class.
 */

#include "atomicData.h"
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

vector<cAtomicData::tPoint2d> cAtomicData::tcs[100]; // Raw total cross section data (data points as pairs of energy and cross section).
float cAtomicData::A[100]; // Atomic weights.
bool cAtomicData::prepared = false;

//===========================================================================================================================================
/* Opens the file "totalCrossSection.dat" and stores the content in the attributes "tcs" and "A".
 * If completed successfully, set the attribute "prepared" to "true".
 * If "prepared" is already "true", this method does nothing.
 */
void cAtomicData::prepare() {
	// Execute if data is not already prepared.
	if (!prepared) {
		string filename = "totalCrossSection.dat"; // Name of the file to read.
		char title[12];							   // Char array to hold the title "atomic-data" read from the file "filename".
		uint32_t tcsNameLength = 0;				   // Length of the table name (no. of characters) to read from the file.
		char* tcsName;							   // Char pointer to hold the table name "totalCrossSection" read from the file.
		uint32_t atomicNumber = 0;				   // Variable to store the atomic number read from the file.
		uint32_t entries = 0;					   // Variable to store the number of entries to read from the file.
		float temp;								   // Variable for temporary storage of float values inside a loop.

		// Use ifstream object for file interaction.
		ifstream input;
		input.open(filename, ios::binary);
		if (!input.is_open())
			throw runtime_error("File failed to open.");
		input.read(title, 11); // Read string "atomic-data".
		if (!strcmp(title, "atomic-data"))
			throw runtime_error("Title is not as expected.");
		title[11] = '\0';
		input.read((char*)&tcsNameLength, sizeof(tcsNameLength)); // Read length of the following string.
		tcsName = new char[tcsNameLength];
		input.read(tcsName, tcsNameLength); // Read string "totalCrossSection".
		tcsName[tcsNameLength] = '\0';

		// Loop through and store the entries for the photon energy in MeV and the cross section data in barn.
		for (unsigned i = 0; i < 100; i++) {
			input.read((char*)&atomicNumber, sizeof(atomicNumber)); // Read atomic number Z.
			input.read((char*)&A[i], sizeof(float)); // Read standard atomic weight and save to array "A".
			input.read((char*)&entries, sizeof(entries)); // Read the number of entries.
			tcs[i].resize(entries); // Set size of vector to number of entries.
			for (unsigned j = 0; j < entries; j++) { // Read energy and cross section values and save to tPoint2d elements in vector "tcs".
				input.read((char*)&temp, sizeof(float));
				tcs[i][j].x = temp;
				input.read((char*)&temp, sizeof(float));
				tcs[i][j].y = temp;
			}
		}

		prepared = true;
	}
}

//===========================================================================================================================================
/* Return the atomic weight for the element of the given atomic number "Z".
 * If the given atomic number is out of range, the method throws an exception.
 */
double cAtomicData::getStdAtomicWeight(unsigned Z) {
	// Check if the given atomic number is within range (between 1 and 100).
	if (Z > 100 || Z < 1)
		throw runtime_error("Atomic number is out of range.");
	return A[Z-1];
}

//===========================================================================================================================================
/* Return the cross section in barn for the given atomic number "Z" and the given energy in keV "energy".
 * Linear interpolation on a log-log scale is applied to the cross section.
 * If the given atomic number is out of range, the method throws an exception.
 * If the given energy is out of range, the method returns the cross section of the energy closest to it.
 */
double cAtomicData::getTotalCrossSection(unsigned Z, double energy) {
	unsigned ip = 0;	  // Variable for the index of the correct entry for interpolation.
	double diff = 0.0;	  // The absolute value of the difference between the energy from tcs and the given energy.
	double minDiff = 1.0; // The minimum value of the above "diff".

	// Check if the given atomic number is within range (between 1 and 100).
	if (Z > 100 || Z < 1)
		throw runtime_error("Atomic number if out of range.");

	int numberOfEntries = tcs[Z - 1].size(); // Number of entries in the tcs vector for the given atomic number.
	double energyMeV = energy / 1000;		 // The given energy is in keV, the energy in tcs is in MeV.

	// Check if the given energy is out of range and if yes, return the closest value (the first or last cross section in barn).
	if (energyMeV <= tcs[Z - 1].front().x)
		return tcs[Z - 1].front().y;
	else if (energyMeV >= tcs[Z - 1].back().x)
		return tcs[Z - 1].back().y;
	
	// Loop through the stored entries in the tcs vector to find the energy that most closely matches the given energy.
	for (unsigned i = 0; i < numberOfEntries; i++) {
		diff = abs(tcs[Z - 1][i].x - energyMeV);
		if (diff < minDiff) {
			minDiff = diff;
			ip = i;
		}
	}
	
	// Calculate the linear interpolation on a log-log scale.
	float energyK = tcs[Z - 1][ip - 1].x;
	float energyK1 = tcs[Z - 1][ip].x;
	float csK = tcs[Z - 1][ip - 1].y;
	float csK1 = tcs[Z - 1][ip].y;
	return csK * exp(log(csK1 / csK) * log(energyMeV / energyK) / log(energyK1 / energyK));
}