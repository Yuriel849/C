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

	cout << "    Test getters and setters " << endl;
	double x = 0;
	double y = 0;
	double z = 0;
	double in[3] = { 0, 0, 0 };
	double out[3] = { 0, 0, 0 };
	particle.setPosition(10, 20, 30);
	particle.setDirection(15, 25, 35);
	particle.getPosition(x, y, z);
	if (x != 10 && y != 20 && z != 30)
		throw runtime_error("Error: get/setPosition(x,y,z) not working.");
	particle.getDirection(x, y, z);
	if (x != 15 && y != 25 && z != 35)
		throw runtime_error("Error: get/setDirection(x,y,z) not working.");
	in[0] = 1;
	in[1] = 2;
	in[2] = 3;
	particle.setPosition(in);
	in[0] = 4;
	in[1] = 5;
	in[2] = 6;
	particle.setDirection(in);
	particle.getPosition(out);
	if (out[0] != 1 && out[1] != 2 && out[2] != 3)
		throw runtime_error("Error: get/setPosition(vector) not working.");
	particle.getDirection(out);
	if (out[0] != 4 && out[1] != 5 && out[2] != 6)
		throw runtime_error("Error: get/setDirection(vector) not working.");
	cout << "    Finished" << endl;

	cout << "    Test minDis2Origin " << endl;
	cout << "    Finished " << endl;

	cout << "    Test minDis2Point " << endl;
	cout << "    Finished " << endl;


}
