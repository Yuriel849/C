/*
 * Filename: main.cpp
 * Author: Myungjun Kim
 * Version: 1.0
 * Date: 31.12.2021
 * Description: Source code file to test the cAtomicData and cMaterial classes.
 */

#include <iostream>
#include "atomicData.h"
#include "material.h"

// Access 'std' namespace where all standard C++ libraries are.
using namespace std;

void testAtomicData();
void testMaterial();

int main() {
	// try-catch-throw mechanism
	try {
		cout << "Test atomicData and material:" << endl;

		testAtomicData();

		testMaterial();

		cout << "Successful run!" << endl;
	}
	// Error that throws an object of class exception.
	// Use exception::what() to get specific error message.
	catch (exception& e) {
		cout << "ERROR: " << e.what() << endl;
	}
	// All other errors.
	// Give general error message.
	catch (...) {
		cout << "ERROR: Unexpected error." << endl;
	}

	return 0;
}

void testAtomicData() {
	cAtomicData atomic;
	
	cout << "  Testing cAtomicData" << endl;

	//================================================================================================================================
	// Prepare the atomic data.
	cout << "    Preparing the atomic data." << endl;
	atomic.prepare();

	//================================================================================================================================
	// Check method getStdAtomicWeight()
	cout << "    Comparing actual atomic weights with the atomic weights from the atomic data." << endl;
	cout << "      Comparing the atomic weights for hydrogen..." << endl;
	if (!(abs(1.008 - atomic.getStdAtomicWeight(1)) < 0.005))
		throw runtime_error("Atomic weight for hydrogen is incorrect.");
	cout << "      Comparing the atomic weights for oxygen..." << endl;
	if (!(abs(15.999 - atomic.getStdAtomicWeight(8)) < 0.005))
		throw runtime_error("Atomic weight for oxygen is incorrect.");
	cout << "      Comparing the atomic weights for silicon..." << endl;
	if (!(abs(28.085 - atomic.getStdAtomicWeight(14)) < 0.005))
		throw runtime_error("Atomic weight for silicon is incorrect.");
	cout << "      => getStdAtomicWeight() tested successfully." << endl;

	//================================================================================================================================
	// Check method getTotalCrossSection
	cout << "    Getting the total cross section for Aluminum (atomic number=13) at 27.9keV." << endl;
	if (!(abs(61.223 - atomic.getTotalCrossSection(13, 27.9)) < 0.005))
		throw runtime_error("Interpolated total cross section is incorrect.");
	cout << "      => getTotalCrossSection() tested successfully." << endl;
}

void testMaterial() {
}