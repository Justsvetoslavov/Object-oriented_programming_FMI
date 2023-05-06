#include "FuelTank.hpp"
#include "insufficient_fuel_error.hpp"

FuelTank::FuelTank(unsigned int id, String manufacturer, String description, double fuelLevel, double capacity) : CarPart(id, manufacturer, description)
{
	setFuelLevel(fuelLevel);
	setCapacity(capacity);
}

void FuelTank::setFuelLevel(double fuelLevel)
{
	if (fuelLevel > 0)
	{
		this->fuelLevel = fuelLevel;
	}
	else
	{
		throw std::logic_error("fuelLevel should be positive number");
	}
}

void FuelTank::setCapacity(double capacity)
{
	if (capacity > 0)
	{
		this->capacity = capacity;
	}
	else
	{
		throw std::logic_error("Capacity should be positive number");
	}
}

bool FuelTank::enoughFuel(double toUse)
{
	return this->fuelLevel > toUse;
}

void FuelTank::use(double toUse)
{
	if (enoughFuel(toUse))
	{
		this->fuelLevel -= toUse;
	}
	else
	{
		throw insufficient_fuel_error().what();
	}
}

void FuelTank::toFill(double toFill)
{
	double emptyCapacity = (this->capacity - this->fuelLevel);
	if (toFill > emptyCapacity)
	{
		toFill - emptyCapacity;
		if (toFill < 0)
		{
			this->fuelLevel += toFill;
			std::cout << "Your tank should more" << toFill << "l to be full";
		}
		else
		{
			this->fuelLevel += toFill;
			if (this->fuelLevel > this->capacity)
			{
				this->fuelLevel = this->capacity;
			}
		}
	}
	else
	{
		throw std::logic_error("You must be fill with positive num");
	}
}

std::ostream& operator<<(std::ostream& os, const FuelTank& fuelTank)
{
	return os << "Fuel level:" << fuelTank.fuelLevel << "l and Capacity:" << fuelTank.capacity << "l";
}