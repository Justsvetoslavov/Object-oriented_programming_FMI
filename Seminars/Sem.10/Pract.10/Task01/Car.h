#pragma once
#include "Accumulator.h"
#include "Engine.h"
#include "Wheel.h"
#include "FuelTank.h"

const int wheelsCount = 4;

class Car{
private:
	FuelTank tank;
	Engine engine;
	Wheel wheels[wheelsCount];
	Accumulator accumulator;
	double kilometers;
	double weight;

public:
	Car(const FuelTank& tank, const Engine& engine, const Wheel* wheels, const Accumulator& accumulator, double kilometers, double weight);

	const FuelTank& GetFuelTank() const;
	double GetWeight() const;
	const Engine& GetEngine() const;

	void Drive(double km);
};

static Car* DragRace(Car* car1, Car* car2);

