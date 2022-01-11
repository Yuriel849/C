/*
 * Filename: main.cpp
 * Author: Myungjun Kim
 * Version: 1.0
 * Date: 04.01.2022
 * Description: Source code file to test the cAtomicData and cMaterial classes.
 */

#include <iostream>
#include "MedImage.h"
#include "MedImageIO.h"

 // Access 'std' namespace where all standard C++ libraries are.
using namespace std;

void testSimulation();
void testMedImage();

int main() {
	// try-catch-throw mechanism
	try {
		cout << "Test SpectrumSimulation project:" << endl;

		testSimulation();
		testMedImage();

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

void testMedImage() {
	cMedImage<double> image; // Medical image
	unsigned size = 99; // Image size

	// Create image initialized with zeros
	image.create(size, size, 0);

	// Draw image
	for (unsigned i = 0; i < size; i++)
		image[i][i] = image[i][size - i - 1] = 1;

	// Set pixel value for black and white
	image.pixelValueForBlack = -1;
	image.pixelValueForWhite = 2;

	// Store image as bitmap file
	cMedImageIO<double>::writeBmp(image, "deleteMe.bmp");
}