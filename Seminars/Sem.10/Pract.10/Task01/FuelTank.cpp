#include "FuelTank.h"

insufficient_fuel_error::insufficient_fuel_error(const char* msg) : logic_error(msg)
{
	//this->error = logic_error(msg);
}

FuelTank::FuelTank(unsigned id, const char* manufacturer, const char* description, double capacity):
	CarPart(id,manufacturer,description)
{
	this->capacity = capacity;
	this->level = capacity;
}

void FuelTank::use(double toUse)
{
	if (toUse > this->level)
	{
		throw insufficient_fuel_error("Not enough fuel available.");
	}

	this->level -= toUse;
}

void FuelTank::fill(double toFill)
{
	if (toFill > capacity - level)
	{
		level = capacity;
	}
	else level += toFill;
}
