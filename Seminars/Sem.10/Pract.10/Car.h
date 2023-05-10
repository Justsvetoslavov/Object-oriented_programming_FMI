#include "Accumulator.h"
#include "CarPart.h"
#include "Engine.h"
#include "FuelTank.h"
#include "Tires.h"
#pragma once

class Car : protected Accumulator, protected CarPart, protected Engine, protected FuelTank, protected Tires
{
	FuelTank fuelTank;
	Engine* engine;
	Tires* tires[4];
	Accumulator* accumulator;
	unsigned kilometers;
	unsigned weight;

public:
	Car(FuelTank, Engine*, Tires* [], Accumulator*, unsigned, unsigned, size_t);
	const FuelTank& getFuelTank();
	Engine* getEngine()const;
	Tires* getTires()const;
	Accumulator* getAccumulator()const;
	unsigned getKilometers()const;
	unsigned getWeight()const;

	void setFuelTank(const FuelTank&);
	void setEngine(Engine*);
	void setTires(Tires*[], size_t);
	void setAccumulator(Accumulator*);
	void setKilometers(unsigned);
	void setWeight(unsigned);

	void drive(double);
};

Car* dragRace(Car* car1, Car* car2);

