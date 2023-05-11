#pragma once

class FuelTank {
	double capacity;
	double currentAmount;

public:
	double GetCapacity() const;
	double GetCurrentAmount() const;

	FuelTank() :FuelTank(50) {};
	FuelTank(double capacity);
	void use(double toUse);
	void fill(double toFill);
};