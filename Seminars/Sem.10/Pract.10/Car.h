#pragma once
#include <iostream>
#include "CarBattery.h"
#include "Engine.h"
#include "Tire.h"
#include "FuelTank.h"

const int TIRES = 4;

class Car
{
	FuelTank fuelTank;
	Engine* engine = nullptr;
	CarBattery* battery = nullptr;
	Tire* tires[TIRES];

	double kilometers;
	double weight;

public:

	Car(FuelTank fuelTank,
		Engine* engine,
		Tire* tires[],
		CarBattery* battery,
		double kilometers,
		double weight,
		double fuelCapacity);

	const FuelTank& getFuelTank() const;

	void drive(double kilometers);
};

