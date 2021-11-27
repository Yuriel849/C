#include "spectrum.h"
#include <iostream>

// Access 'std' namespace where all standard C++ libraries are.
using namespace std;

void testSpectrum();

int main() {
	// try-catch-throw mechanism
	try {
		cout << "Test cSpectrum" << endl;

		// 'throw' can be used without an argument,
		// but this terminates the program with only an error message from the operating system.
		//throw bad_alloc();

		testSpectrum();

		cout << "successful run" << endl;
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

void testSpectrum() {
	cSpectrum spec; // Test spectrum

	// Check size and resize
	cout << "  check size() and resize()" << endl;
	if (spec.size() != 0)
		throw runtime_error("Unexpected size in spectrum.");
	spec.resize(100);
	if (spec.size() != 100)
		throw runtime_error("Unexpected size in spectrum.");
	cout << "    finished" << endl;

	// Check access of single elements with brackets
	cout << "  check single element access" << endl;
	spec.resize(25);
	for(unsigned i = 0; i < 25; i++)
		spec[i] = 0;
	cout << "    finished" << endl;

	// Check access of whole spectrum
	// 1. Write one value to all elements.
	// 2. Copy vector to spectrum.
	// 3. Copy spectrum to spectrum.

	// Check calculation functions
	// 1. Add spectrum to spectrum elementwise.
	// 2. Multiply spectrum by spectrum elementwise.
	// 3. Multiply all elements by one value.
	// 4. Apply exponential function to all elements.
	// 5. Evaluate sum of all elements.

	// Check readSpectrum function
	cout << "  check readSpectrum()" << endl;
	string filename = "SRO33100ROT350.dat";
	double tubeVoltage = 75.0;
	double minEnergy = 10.0;
	string spectrum = "SRO33100-ROT350";
	spec.readSpectrum(filename, tubeVoltage, minEnergy, spectrum);
	spec.printData();
	cout << "    finished" << endl;

	// Check the writeCsv function
	cout << "  check writeCsv()" << endl;
	spec.readSpectrum(filename, 40.0, minEnergy, spectrum);
	spec.writeCsv("TubeVoltage_40kV_MinEnergy_10keV_spectrum.csv", minEnergy, 40.0);
	spec.readSpectrum(filename, tubeVoltage, minEnergy, spectrum);
	spec.writeCsv("TubeVoltage_75kV_MinEnergy_10keV_spectrum.csv", minEnergy, tubeVoltage);
	spec.readSpectrum(filename, 100.0, minEnergy, spectrum);
	spec.writeCsv("TubeVoltage_100kV_MinEnergy_10keV_spectrum.csv", minEnergy, 100.0);
	spec.readSpectrum(filename, 150.0, minEnergy, spectrum);
	spec.writeCsv("TubeVoltage_150kV_MinEnergy_10keV_spectrum.csv", minEnergy, 150.0);
	cout << "    finished" << endl;
}
