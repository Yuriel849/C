#include "spectrum.h"
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

cSpectrum::cSpectrum(const cSpectrum& spec) {
	// *this = spec;
	// The above line uses the assignment operator, 'cSpectrum& cSpectrum::operator=(const cSpectrum& spec)'.
	// Problem is it has to call another function and it is better to use one line of duplicate code as below.

	data = spec.data;
}

size_t cSpectrum::size() {
	return data.size();
}

void cSpectrum::resize(size_t newSize) {
	data.resize(newSize);
}

double& cSpectrum::operator[](size_t index) {
	if (index >= data.size())
		throw runtime_error("Index out of range in class cSpectrum.");

	return data[index];
}

cSpectrum& cSpectrum::operator=(double value) {
	for (unsigned i = 0; i < size(); i++)
		data[i] = value;
	return *this;
}

cSpectrum& cSpectrum::operator=(const std::vector<double>& spec) {
	for (unsigned i = 0; i < spec.size(); i++)
		data[i] = spec[i];
	return *this;
}

cSpectrum& cSpectrum::operator=(const cSpectrum& spec) {
	data = spec.data;

	return *this;
}

cSpectrum& cSpectrum::operator+=(const cSpectrum& summand) {
	if (size() != summand.data.size())
		throw runtime_error("Spectrum sizes do not match.");

	for (unsigned i = 0; i < size(); i++)
		data[i] += summand.data[i];
}

cSpectrum& cSpectrum::operator*=(const cSpectrum& factor) {
	if (size() != factor.data.size())
		throw runtime_error("Spectrum sizes do not match.");

	for (unsigned i = 0; i < size(); i++)
		data[i] *= factor.data[i];

	return *this;
}

cSpectrum& cSpectrum::operator*=(double factor) {
	for (unsigned i = 0; i < size(); i++)
		data[i] *= factor;
	return *this;
}

cSpectrum& cSpectrum::exp() {
	for (unsigned i = 0; i < size(); i++)
		data[i] = std::exp(data[i]);
	return *this;
}

double cSpectrum::sum() {
	double sum = 0;
	for (unsigned i = 0; i < size(); i++)
		sum += data[i];
	return sum;
}

/*
 * Read x-ray spectra provided via binary data files.
 */
void cSpectrum::readSpectrum(const std::string& filename, double tubeVoltage, double& minEnergy, std::string& spectrumName) {
	char title[15];
	uint32_t specNameLength = 0;
	char* specName;
	uint32_t specNumber = 0;
	float loopTubeVoltage = -10.0;
	float loopMinEnergy = 0.0;
	uint32_t loopTableLength = 0;
	float temp;

	// Use ifstream object for file interaction.
	ifstream input;
	// Open file with mode ios::binary.
	input.open(filename, ios::binary);
	// Check if the file is open and throw exception if not.
	if (!input.is_open())
		throw runtime_error("File failed to open.");
	// Read from file and validate the title is "x-ray spectrum".
	input.read(title, 14);
	if (!strcmp(title, "x-ray spectrum"))
		throw runtime_error("Title is not as expected.");
	title[14] = '\0';
	// Read string length, string itself, and number of spectra.
	input.read((char*) &specNameLength, sizeof(specNameLength));
	specName = new char[specNameLength];
	input.read(specName, specNameLength);
	input.read((char*) &specNumber, sizeof(specNumber));

	// LOOP
	do {
		// Read tube voltage, minimum energy, and table length.
		input.read((char*) &loopTubeVoltage, sizeof(loopTubeVoltage));
		// If tube voltage matches parameter, read the whole table; else, skip with seekg().
		if (!(abs(tubeVoltage - loopTubeVoltage) < 0.001))
			continue;
			/*
			input.seekg(
				(sizeof(loopMinEnergy) + sizeof(loopTableLength) + (sizeof(loopMinEnergy) * loopTableLength)),
				input.cur);
			*/
		input.read((char*) &loopMinEnergy, sizeof(loopMinEnergy));
		input.read((char*) &loopTableLength, sizeof(loopTableLength));

		cout << "      Voltage : " << loopTubeVoltage << " Energy : " << loopMinEnergy << " Length : " << loopTableLength << endl;
		data.resize(0);
		for (unsigned i = 0; i < loopTableLength; i++) {
			input.read((char*)&temp, sizeof(loopTableLength));
			data.push_back(temp);
		}
		break; // Break loop if tube voltage matches
	} while (input.peek() != EOF);
	// Break loop if tube voltage matches or all available spectra read
	
	// Throw exception if matching tube voltage not found
	if (loopTubeVoltage != tubeVoltage)
		throw runtime_error("Target tube voltage not found.");
}

void cSpectrum::printData() {
	for (unsigned i = 0; i < data.size(); i++)
		cout << "      IDX " << i << " : " << data[i] << endl;
}

void cSpectrum::writeCsv(const std::string& filename, double minEnergy, double tubeVoltage) {
	ofstream out;
	double increment = (tubeVoltage - minEnergy) / data.size();

	out.open(filename); // Default is text output mode

	out << "energy,intensity" << endl;

	// Add all spectrum elements in separate rows of energy, intensity
	for (unsigned i = 0; i < data.size(); i++)
		out << minEnergy + (increment * i) << "," << data[i] << endl;

	out << tubeVoltage << ", 0" << endl; // Add last line with tube voltage as energy and zero intensity
}
