/*
 * Filename: main.cpp
 * Author: Myungjun Kim
 * Version: 1.0
 * Date: 04.01.2022
 * Description: Source code file to test the cAtomicData and cMaterial classes.
 */

#include <iostream>

 // Access 'std' namespace where all standard C++ libraries are.
using namespace std;

void testSimulation();

int main() {
	// try-catch-throw mechanism
	try {
		cout << "Test SpectrumSimulation project:" << endl;

		testSimulation();

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

void testSimulation() {

}