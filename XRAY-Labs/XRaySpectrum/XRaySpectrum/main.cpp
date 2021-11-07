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
}
