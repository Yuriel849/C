/*
 * Filename: main.cpp
 * Author: Myungjun Kim
 * Version: 1.2
 * Date: 02.01.2022
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
	// Catch errors of that throw objects of class exception.
	catch (exception& e) {
		cout << "ERROR: " << e.what() << endl;
	}
	// Catch all other errors.
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
	cMaterial mat;

	cout << "  Testing cMaterial" << endl;

	//================================================================================================================================
	// Check method setName() and getName()
	cout << "    Checking the methods setName() and getName()." << endl;
	mat.setName("MATERIAL-04");
	if (mat.getName().compare("MATERIAL-04") != 0)
		throw runtime_error("setName() and getName() not functioning correctly.");

	//================================================================================================================================
	// Check method addElement() and getNoOfElements()
	cout << "    Checking the methods addElement() and getNoOfElements() with water (H2O)." << endl;
	mat.addElement(8, 1);
	mat.addElement(1, 2);
	if (mat.getNoOfElements() != 2)
		throw runtime_error("addElement() and getNoOfElements() not functioning correctly.");

	//================================================================================================================================
	// Check method getAtomicNumber()
	cout << "    Checking the method getAtomicNumber()." << endl;
	if (mat.getAtomicNumber(0) != 8)
		throw runtime_error("getAtomicNumber() not functioning correctly.");

	//================================================================================================================================
	// Check method getFraction()
	cout << "    Checking the method getFraction()." << endl;
	if (mat.getFraction(0) != 1)
		throw runtime_error("getFraction() not functioning correctly.");

	//================================================================================================================================
	// Check method setDensity() and getDensity()
	cout << "    Checking the methods setDensity() and getDensity()." << endl;
	mat.setDensity(101.505);
	if (mat.getDensity() != 101.505)
		throw runtime_error("setDensity() and getDensity() not functioning correctly.");

	//================================================================================================================================
	// Check method getAttCoeff()
	cout << "    Checking the method getAttCoeff() with water (H2O) at 50keV." << endl;
	mat.setDensity(1.0);
	cout << "      Expected attenuation coefficient=2.270e+23, calculated coefficient=" << mat.getAttCoeff(50) << endl;

	//================================================================================================================================
	// Check method getAttSpec()
	cout << "    Checking the method getAttSpec() with minimum energy=100, tube voltage=1000, step size=50." << endl;
	std::vector<double> spec;
	mat.getAttSpec(spec, 100, 1000, 50);
	for (double value : spec)
		cout << "      " << value << endl;

	//================================================================================================================================
	// Check method getMeanFreePath()
	cout << "    Checking the method getMeanFreePath() with water (H2O) at 50keV." << endl;
	if (mat.getMeanFreePath(50) != (1/mat.getAttCoeff(50)))
		throw runtime_error("getMeanFreePath() not functioning correctly.");

	cout << "      => All cMaterial methods tested successfully." << endl;
}