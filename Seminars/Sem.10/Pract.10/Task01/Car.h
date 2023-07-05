#pragma once

#include "CarBattery.h"
#include "Engine.h"
#include "FuelTank.h"
#include "Tire.h"

class Car {
	FuelTank _fuelTank;
	Engine _engine;
	Tire _tires[4];
	CarBattery _carBattery;
	double _mileage = 0;
	unsigned _weight = 0;

public:
	Car() = default;
	Car(const FuelTank& fuelTank, const Engine& engine, const Tire tires[4], const CarBattery& carBattery, double mileage, unsigned weight);
	const FuelTank& getFuelTank() const;
	bool drive(double km);

	void fillTank(double toFill);

	double getMileage() const;

	friend Car* dragRace(Car* car1, Car* car2);
};

Car* dragRace(Car* car1, Car* car2);