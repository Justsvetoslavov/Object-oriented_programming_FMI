#pragma once
#include "CarPart.h"
class Wheel : public CarPart{
private:
	double width = 0;
	double profile = 0;
	double diameter = 0;
	
public:
	Wheel() = default;
	Wheel(int id, const char* name, const char* details, double width, double profile, double diameter);
	friend std::ostream& operator<<(std::ostream& os, const Wheel& other);

	void SetWidth(double width);
	void SetProfile(double profile);
	void SetDiameter(double diameter);
};

std::ostream& operator<<(std::ostream& os, const Wheel& other);