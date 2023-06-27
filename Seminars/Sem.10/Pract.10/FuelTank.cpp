#include <stdexcept>
#include "FuelTank.h"
#include "insufficient_fuel_exception.h"

bool static inline getAbs(double a)
{
	return a < 0 ? -a : a;
}

bool static inline areEqual(double a, double b)
{
	static const double EPSILON = 0.0001;
	return getAbs(a - b) < EPSILON;
}

FuelTank::FuelTank(double capacity)
{
	_capacity = _currentLevel = capacity;
}

void FuelTank::use(double amount)
{
	if (amount < 0)
		throw std::invalid_argument("Invalid input data. Negative amount passed.");

	if (_currentLevel - amount < 0 && !areEqual(amount, _currentLevel))
		throw insufficient_fuel_exception("Not enough fuel in tank.");

	_currentLevel -= amount;
}

void FuelTank::fill(double amount)
{
	if (amount < 0)
		throw std::invalid_argument("Invalid input data. Negative amount passed.");

	if (_currentLevel + amount > _capacity && !areEqual(amount + _currentLevel, _capacity))
		_currentLevel = _capacity;
	else
		_currentLevel += amount;
}

double FuelTank::getCapacity() const
{
	return _capacity;
}

double FuelTank::getCurrentLevel() const
{
	return _currentLevel;
}
