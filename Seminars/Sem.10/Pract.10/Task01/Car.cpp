#include "Car.h"

Car::Car(const FuelTank& fuelTank, const Engine& engine, const Tire* tires, const CarBattery& carBattery,
	const double distanceKm, const unsigned weight)
{
	this->fuelTank = fuelTank;
	this->engine = engine;
	for (size_t i = 0; i < 4; i++)
	{
		this->tires[i] = tires[i];
	}
	this->carBattery = carBattery;
	this->distanceKm = distanceKm;
	this->weight = weight;
}

const FuelTank& Car::getFuelTank() const
{
	return this->fuelTank;
}

void Car::drive(const double km)
{
	this->fuelTank.use(km); // damn 100 na 100 razhod
	this->distanceKm += km;
}

Car* dragRace(Car* car1, Car* car2)
{
	const double kmRace = 0.4;
	bool firstFinished = true;
	bool secondFinished = true;

	try
	{
		car1->drive(kmRace);
	}
	catch (insufficient_fuel_error&)
	{
		firstFinished = false;
	}
	try
	{
		car2->drive(kmRace);
	}
	catch (insufficient_fuel_error&)
	{
		secondFinished = false;
	}

	if (firstFinished)
	{
		if (secondFinished)
		{
			return car1->weight / car1->engine.horsePower >
				car2->weight / car2->engine.horsePower ?
				car1 : car2;
		}
		return car1;
	}
	if (secondFinished)
	{
		return car2;
	}
	return nullptr;
}
