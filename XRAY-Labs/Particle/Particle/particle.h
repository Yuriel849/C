#pragma once

class cParticle {
private:
	double pos[3] = { 0, 0, 0 }; // Current position of the x-ray pencil beam (Unit: meter)
	double dir[3] = { 0, 0, 0 }; // Current direction of the x-ray pencil beam (Unit: radian)
public:
	cParticle() {};
	cParticle(const cParticle &original);
	~cParticle() {};
	void getPosition(double& x, double& y, double& z) const; // "&" (reference operator): Directly write to the passed arguments.
	void getDirection(double& x, double& y, double& z) const;
	void setPosition(double x, double y, double z);
	void setDirection(double x, double y, double z);
	void getPosition(double p[3]) const; // Write to vector "p" instead of returning array as pointer.
	void getDirection(double d[3]) const;
	void setPosition(double p[3]); // Take new values from vector "p".
	void setDirection(double d[3]);

	double minDist2Origin() const; // Evaluates minimum distance between current position of x-ray pencil beam and origin.
	double minDist2Point(double x, double y, double z) const; // Evaluates minimum distance betwee current position and given point (x,y,z).
	double minDist2Point(double p[3]) const;

	friend void testParticle(); // "friend" gives this function access to private attributes in this class.
};