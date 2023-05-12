#pragma once
#include "CarPart.h"
class Wheel : public CarPart
{
private:
	double width = 0;
	double profile = 0;
	double diameter = 0;

public: 
	Wheel() = default;
	Wheel(unsigned id, const MyString& manufacturerName, const MyString& descripiton,
		double width, double profile, double diameter);

	void SetWidth(double width);
	void SetProfile(double profile);
	void SetDiameter(double diameter);

	friend std::ostream& operator<<(std::ostream& os, const Wheel& wheel);
};

