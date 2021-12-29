#include "material.h"

using namespace std;

cMaterial::cMaterial() {
	clear();
}

cMaterial::cMaterial(const cMaterial& material) {
	Z = material.Z;
	fraction = material.fraction;
	density = material.density;
	name = material.name;
}

void cMaterial::clear() {
	name = "new material";
	density = 1.0;
	Z.clear();
	fraction.clear();
}

void cMaterial::setName(const std::string& newName) {
	name = newName;
}

const std::string& cMaterial::getName() {
	return name;
}

void cMaterial::addElement(unsigned newZ, double newFraction) {
	Z.push_back(newZ);
	fraction.push_back(newFraction);
}

unsigned cMaterial::getNoOfElements() {
	return Z.size();
}

unsigned cMaterial::getAtomicNumber(unsigned i) {
	return Z.at(i);
}

double cMaterial::getFraction(unsigned i) {
	return fraction.at(i);
}

void cMaterial::setDensity(double newDensity) {
	density = newDensity;
}

double cMaterial::getDensity() {
	return density;
}
