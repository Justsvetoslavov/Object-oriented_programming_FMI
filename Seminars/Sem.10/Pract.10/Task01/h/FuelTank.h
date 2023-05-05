#pragma once
#include <iostream>

class FuelTank
{
	double  capacity;
	double currentFuel;

public:

	FuelTank(double capacity);
	double getcurrentFuel()const;
	void useFuel(double toUse);
	void fillFuel(double toFill);

};
