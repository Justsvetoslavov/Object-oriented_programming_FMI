#pragma once

class FuelTank
{
	double _capacity = 0;
	double _currentLevel = 0;

public:
	FuelTank(double);

	void use(double);
	void fill(double);

	double getCapacity() const;
	double getCurrentLevel() const;
};
