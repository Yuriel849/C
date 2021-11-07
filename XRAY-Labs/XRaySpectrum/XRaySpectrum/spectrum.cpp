#include "spectrum.h"
#include <iostream>

using namespace std;

cSpectrum::cSpectrum(const cSpectrum& spec) {
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
	cSpectrum(spec);

	return *this;
}
