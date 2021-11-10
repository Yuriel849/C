#include "spectrum.h"
#include <iostream>
#include <string>
#include <cmath>

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
}

cSpectrum& cSpectrum::operator*=(double factor) {
	for (unsigned i = 0; i < size(); i++)
		data[i] *= factor;
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
