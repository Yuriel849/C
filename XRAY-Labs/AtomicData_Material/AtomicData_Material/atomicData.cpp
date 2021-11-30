#include "atomicData.h"
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

vector<cAtomicData::tPoint2d> cAtomicData::tcs[100];
float cAtomicData::A[100]; // Atomic weights.
bool cAtomicData::prepared = false;

void cAtomicData::prepare() {
	if (!prepared) { // Only prepare the data if not prepared.
		// Open the file "totalCrossSection.dat"
		// Load data into tcs and A arrays.

		string filename = "totalCrossSection.dat";
		char title[12];
		uint32_t tcsNameLength = 0;
		char* tcsName;
		uint32_t atomicNumber = 0;
		uint32_t entries = 0;
		float temp;

		// Use ifstream object for file interaction.
		ifstream input;
		input.open(filename, ios::binary);
		if (!input.is_open())
			throw runtime_error("File failed to open.");
		input.read(title, 11); // Read string "atomic-data".
		title[11] = '\0';
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
			tcs[i].resize(entries); // Set size of vector.
			for (unsigned j = 0; j < entries; j++) {
				input.read((char*)&temp, sizeof(float));
				tcs[i][j].x = temp;
				input.read((char*)&temp, sizeof(float));
				tcs[i][j].y = temp;
			}
		}
	}
	prepared = true;
}

// Return the atomic weight for the given atomic number.
double cAtomicData::getStdAtomicWeight(unsigned Z) {
	if (Z > 100 || Z < 1)
		throw runtime_error("Atomic number is out of range.");
	return A[Z-1];
}

// Parameter "energy" is energy in keV.
// Returns cross section in barn as double value.
double cAtomicData::getTotalCrossSection(unsigned Z, double energy) {
	double returnValue = 0;

	if (Z > 100 || Z < 1)
		throw runtime_error("Atomic number if out of range.");

	int numberOfEntries = tcs[Z - 1].size();
	double energyMeV = energy / 1000;

	if (energy <= tcs[Z - 1].front().x)
		return tcs[Z - 1].front().y;
	if (energy >= tcs[Z - 1].back().x)
		return tcs[Z - 1].back().y;


	for (unsigned i = 0; i < numberOfEntries; i++) {

	}
	
	for (unsigned i = 0; i < numberOfEntries; i++) {
		if (tcs[Z - 1][i].x == energy)
			returnValue = tcs[Z - 1][i].y;
	}

	return 0.0;
}
