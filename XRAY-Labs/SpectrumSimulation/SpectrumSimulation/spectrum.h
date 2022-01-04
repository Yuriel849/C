// Ensures this file is compiled only once per .cpp file.
#pragma once

#include <vector>
#include <string>

class cSpectrum {
private:
	// Vector of double precision floating point variables.
	std::vector<double> data;
public:
	cSpectrum() {};
	cSpectrum(const cSpectrum& spec);
	~cSpectrum() {};
	size_t size(); // Get the size of 'spec'.
	void resize(size_t newSize); // Set the size of 'spec'.
	double& operator[](size_t index); // Access single elements with brackets.
	cSpectrum& operator=(double value); // Access entire spectrum: Write single value to all elements.
	cSpectrum& operator=(const std::vector<double>& spec); // Access entire spectrum: Copy vector to spectrum.
	cSpectrum& operator=(const cSpectrum& spec); // Access entire spectrum: Copy spectrum to spectrum.

	cSpectrum& operator+=(const cSpectrum& summand); // Add one spectrum to another.
	cSpectrum& operator*=(const cSpectrum& factor); // Multiply one spectrum by another elementwise.
	cSpectrum& operator*=(double factor); // Multiple all elements by one value.
	cSpectrum& exp(); // Apply exponential function on all elements.
	double sum(); // Evaluate the sum of all elements.

	void readSpectrum(const std::string& filename, double tubeVoltage, double& minEnergy, std::string& spectrumName);

	void printData();

	void writeCsv(const std::string& filename, double minEnergy, double tubeVoltage);

};
