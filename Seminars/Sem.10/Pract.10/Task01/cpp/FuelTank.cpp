#include "FuelTank.h"
#include<iostream>
#include "insufficient_fuel_error.h"

FuelTank::FuelTank(double capacity)
{
	this->capacity = capacity;
	currentFuel = capacity;
}

double FuelTank::getcurrentFuel()const 
{
	return currentFuel;
}

void FuelTank::useFuel(double toUse)
{
	if (currentFuel < toUse)
	{
		throw insufficient_fuel_error("The fuel is not enough!");
	}
	currentFuel -= toUse;
}

void FuelTank::fillFuel(double toFill)
{
	currentFuel += toFill;
	if (currentFuel >= capacity)
	{
		throw insufficient_fuel_error("The fuel is full!");
	}
}