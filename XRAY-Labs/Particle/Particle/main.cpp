#include "particle.h"
#include <iostream>

// Access 'std' namespace where all standard C++ libraries are.
using namespace std;

void testParticle();

int main() {
	try {
		cout << "Test cParticle" << endl;

		testParticle();

		cout << "successful run" << endl;
	}
	catch (exception& e) {
		cout << "ERROR: " << e.what() << endl;
	}
	catch (...) {
		cout << "ERROR: Unexpected error." << endl;
	}

	return 0;
}

void testParticle() {
	cParticle particle; // Test particle

}
