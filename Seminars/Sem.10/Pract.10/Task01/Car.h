#pragma once
#include "Engine.h"
#include "Accumulator.h"
#include "Wheel.h"
#include "FuelTank.h"
#include "insufficient_fuel_error.h"
const int WHEELS_COUNT = 4;

class Car
{
private:
	FuelTank fuelTank;
	Engine engine;
	Wheel wheels[WHEELS_COUNT];
	Accumulator accumulator;
	unsigned kilometers;
	double weight;

public:
	Car(const FuelTank& fuelTank, const Engine& engine, const Wheel* wheels,
		const Accumulator& accumulator, unsigned kilometers, double weight);

	const FuelTank& GetFuelTank() const;
	double GetWeight() const;
	const Engine& GetEngine() const;
	void Drive(double km);
};

Car* DragRace(Car* car1, Car* car2);

