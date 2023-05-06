#pragma once
#include "CarPart.hpp"

class FuelTank : protected CarPart
{
private:
	double fuelLevel;
	double capacity;
public:
	FuelTank() = default;

	FuelTank(unsigned int id, String manufacturer, String description, double fuelLevel, double capacity);

	void setFuelLevel(double fuelLevel);

	void setCapacity(double capacity);

	bool enoughFuel(double toUse);

	void use(double toUse);

	void toFill(double toFill);

	friend std::ostream& operator<<(std::ostream& os, const FuelTank& fuelTank);
};