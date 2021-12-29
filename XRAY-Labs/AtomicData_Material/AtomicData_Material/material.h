#pragma once

#include <vector>
#include <string>

class cMaterial {
private:
	std::vector<unsigned> Z;
	std::vector<double> fraction;
	double density;
	std::string name;
public:
	cMaterial();
	cMaterial(const cMaterial& material);
	~cMaterial() {};
	void clear(); // Sets name as "new material", deletes all from Z and fraction, sets density as 1 g/cm^3.
	void setName(const std::string &newName);
	const std::string &getName();
	void addElement(unsigned newZ, double newFraction);
	unsigned getNoOfElements();
	unsigned getAtomicNumber(unsigned i);
	double getFraction(unsigned i);
	void setDensity(double newDensity);
	double getDensity();
	double getAttCoeff(double energy);
	void getAttSpec(std::vector<double> &spec, double minEnergy, double tubeVoltage, unsigned energySteps);
	double getMeanFreePath(double energy);
};