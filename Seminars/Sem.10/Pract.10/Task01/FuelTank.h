#pragma once

class FuelTank {
	double _capacity; 
	double _fullness;

public:
	FuelTank(double capacity);
	void use(double toUse);
	void fill(double toFill);
};