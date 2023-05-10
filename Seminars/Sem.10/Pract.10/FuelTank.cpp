#include "FuelTank.h"
#include <stdexcept>
#include <string>
#pragma warning (disable : 4996)



FuelTank::FuelTank(unsigned capacity, unsigned fullness)
{
	setCapacity(capacity);
}

unsigned FuelTank::getCapacity() const
{
	return capacity;
}

unsigned FuelTank::getCurrFullness() const
{
	return currFullness;
}

void FuelTank::setCapacity(unsigned capacity)
{
	if (capacity < 0)
		capacity = 0;
	this->capacity = capacity;
	this->currFullness = capacity;
}

void FuelTank::use(double toUse)
{
	currFullness -= toUse;
	if (currFullness < 0)
		throw insufficient_fuel_error("There isn't enought fuel in the car.");
}

void FuelTank::fill(double toFill)
{
	currFullness += toFill;
	if (currFullness > capacity)
		currFullness = capacity;
}

