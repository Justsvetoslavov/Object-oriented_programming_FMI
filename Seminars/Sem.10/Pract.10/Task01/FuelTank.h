#pragma once
#include "insufficient_fuel_error.h"

class FuelTank{
private:
	double capacity = 0;
	double fullness = 0;

public:
	FuelTank() = default;
	FuelTank(double capacity);

	void Use(double toUse);
	void Fill(double ToFill);

	double GetFullness() const;
};

