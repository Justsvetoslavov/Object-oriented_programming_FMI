#pragma once
#include "CarPart.h"

class insufficient_fuel_error : public std::logic_error
{
	//std::logic_error error;

public:
	insufficient_fuel_error(const char* msg);
};

class FuelTank : public CarPart
{
public:
	double capacity = 0;
	double level = 0;

	FuelTank() = default;
	FuelTank(unsigned id, const char* manufacturer, const char* description,
		double capacity);

	void use(double toUse);
	void fill(double toFill);

};

