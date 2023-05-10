#pragma once

class insufficient_fuel_error : public std::logic_error {
public:
	explicit insufficient_fuel_error(const char* message) : std::logic_error(message) {}
};

class FuelTank
{
	double capacity;
	double currFullness;

public:
	FuelTank() = default;
	FuelTank(unsigned, unsigned);
	unsigned getCapacity()const;
	unsigned getCurrFullness()const;

	void setCapacity(unsigned);

	void use(double);
	void fill(double);
};
