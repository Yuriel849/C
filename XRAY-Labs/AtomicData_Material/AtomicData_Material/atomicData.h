/*
 * Filename: atomicData.h
 * Author: Myungjun Kim
 * Version: 1.0
 * Date: 31.12.2021
 * Description: Header file for the cAtomicData class.
 */

// Ensures this file is compiled only once per .cpp file.
#pragma once

#include <vector>
#include <string>

class cAtomicData {
public:
	typedef struct {
		float x; // Energy in MeV.
		float y; // Cross-section in barn.
	} tPoint2d;
private:
	static std::vector<tPoint2d> tcs[100]; // 100-size array of vectors of tPoint2d objects.
	static float A[100]; // Atomic weights.
	static bool prepared; // Indicator, is data prepared or not?
public:
	cAtomicData() {};
	~cAtomicData() {};
	void prepare();
	double getStdAtomicWeight(unsigned Z);
	double getTotalCrossSection(unsigned Z, double energy);
};
