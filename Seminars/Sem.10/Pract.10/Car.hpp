#pragma once
#include "Tyre.hpp"
#include "Engine.hpp"
#include "Accumulator.hpp"
#include "FuelTank.hpp"
class Car
{
private:
	FuelTank fuelTank;
	Engine engine;
	Tyre tyre[4];
	Accumulator accumulator;
	double kmDrove;
	double weight;
public:
	Car(FuelTank fuelTank, Engine engine, Tyre tyre[4], Accumulator accumulator, double kmDrove, double weight);

	void setFuelTank(FuelTank& fuelTank);

	void setEngine(Engine& engine);

	void setTyres(Tyre tyre[4]);

	void setAccumulator(Accumulator& accumulator);

	void setKmDrove(double kmDrove);

	void setWeight(double weight);

	const FuelTank& getFuelTank();

	void drive(double km);

	friend Car* dragRace(Car* car1, Car* car2);
};
