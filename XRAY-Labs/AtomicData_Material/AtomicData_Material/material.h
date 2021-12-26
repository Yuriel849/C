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
	addElement();
	getNoOfElements();
	getAtomicNumber();
	getFraction();
	setDensity();
	getDensity();
	getAttCoeff();
	getAttSpec();
	getMeanFreePath();
};