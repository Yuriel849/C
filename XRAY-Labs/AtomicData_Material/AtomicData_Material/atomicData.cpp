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
		char title[11];							   // Char array to hold the title "atomic-data" read from the file "filename".
		uint32_t tcsNameLength = 0;				   // Length of the table name (no. of characters) to read from the file.
		char* tcsName;							   // Char pointer to hold the table name "totalCrossSection" read from the file.
		uint32_t atomicNumber = 0;				   // Variable to store the atomic number read from the file.
		uint32_t entries = 0;					   // Variable to store the number of entries to read from the file.
		float temp;								   // Variable for temporary storage of float values inside a loop.

		ifstream input; // Use ifstream object for file interaction.
		input.open(filename, ios::binary);
		if (!input.is_open())
			throw runtime_error("File failed to open.");
		input.read(title, 11); // Read string "atomic-data".
		if (!strcmp(title, "atomic-data"))
			throw runtime_error("Title is not as expected.");
		input.read((char*)&tcsNameLength, sizeof(tcsNameLength)); // Read length of the following string.
		tcsName = new char[tcsNameLength];
		input.read(tcsName, tcsNameLength); // Read string "totalCrossSection".
		title[tcsNameLength] = '\0';

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
	}
	prepared = true;
}

//===========================================================================================================================================
/* Return the atomic weight for the element of the given atomic number "Z".
 * If the given atomic number is out of range, the method throws an exception.
 */
double cAtomicData::getStdAtomicWeight(unsigned Z) {
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
	unsigned ip = 0;

	if (Z > 100 || Z < 1)
		throw runtime_error("Atomic number if out of range.");

	int numberOfEntries = tcs[Z - 1].size();
	double energyMeV = energy / 1000; // The given energy is in keV, the energy in tcs is in MeV.

	if (energyMeV <= tcs[Z - 1].front().x)
		return tcs[Z - 1].front().y;
	else if (energyMeV >= tcs[Z - 1].back().x)
		return tcs[Z - 1].back().y;
	
	for (unsigned i = 0; i < numberOfEntries; i++) {
		if (!(abs(tcs[Z-1][i].x - energyMeV) < 0.001)) // tcs.x is a float, energyMeV is a double, check that the difference is not more than 0.1%.
			ip = i;
	}
	
	float energyK = tcs[Z - 1][ip].x;
	float energyK1 = tcs[Z - 1][ip+1].x;
	float csK = tcs[Z - 1][ip].y;
	float csK1 = tcs[Z - 1][ip + 1].x;
	return csK * exp(log(csK1 / csK) * log(energyMeV / energyK) / log(energyK1 / energyK));
}
