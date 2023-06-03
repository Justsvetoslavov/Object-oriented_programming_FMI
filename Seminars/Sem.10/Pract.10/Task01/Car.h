#pragma once
#include "CarBattery.h"
#include "Engine.h"
#include "FuelTank.h"
#include "Tire.h"

class Car
{
	FuelTank fuelTank{};
	Engine engine{};
	Tire tires[4]{};
	CarBattery carBattery{};
	double distanceKm = 0;
	unsigned weight = 0;

public:
	Car(const FuelTank& fuelTank, const Engine& engine, const Tire* tires, const CarBattery& carBattery,
		double distanceKm, unsigned weight);

	const FuelTank& getFuelTank() const;
	void drive(double km);

	friend Car* dragRace(Car* car1, Car* car2);
};

Car* dragRace(Car* car1, Car* car2);

