#include <iostream>

// Access 'std' namespace where all standard C++ libraries are.
using namespace std;

void testAtomicData();
void testMaterial();

int main() {
	// try-catch-throw mechanism
	try {
		cout << "Test atomicData and material" << endl;

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

void testAtomicData() {
}

void testMaterial() {
}
