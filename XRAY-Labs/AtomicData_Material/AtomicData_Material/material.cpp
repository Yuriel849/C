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
