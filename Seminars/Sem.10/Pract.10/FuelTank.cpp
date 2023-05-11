#include "FuelTank.h"
#include "customErrors.h"
#include <iostream>

double FuelTank::GetCapacity() const
{
	return capacity;
}

double FuelTank::GetCurrentAmount() const
{
	return currentAmount;
}

FuelTank::FuelTank(double capacity)
{
	if (capacity <= 0) throw std::runtime_error("capacity must be > 0");
	this->capacity = capacity;
	currentAmount = capacity;
}

void FuelTank::use(double toUse)
{
	if (toUse <= 0) throw std::runtime_error("value must be > 0");
	if (currentAmount - toUse < 0) throw insufficient_fuel_error("don\'sst have enough fuel");
	else currentAmount -= toUse;
}

void FuelTank::fill(double toFill)
{
	if (toFill <= 0) throw std::runtime_error("value must be > 0");
	if (currentAmount + toFill > capacity) currentAmount = capacity;
	else currentAmount += toFill;
}
