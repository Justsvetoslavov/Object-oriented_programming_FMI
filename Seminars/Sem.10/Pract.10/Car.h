#pragma once
#include "FuelTank.h"
#include "Engine.h"
#include "Tire.h"
#include "Аccumulator.h"

class Car {
	FuelTank tank;
	Engine engine;
	Tire tires[4];
	Accumulator accumulator;
	size_t kilometers;
	size_t weight;
public:
	Car(const Engine& engine, const Tire* tires, const Accumulator& accumulator,
		size_t killometers, size_t weight, size_t tankCapacity);

	const Engine& getEngine() const;
	const Accumulator& getAccumulator() const;
	const Tire* getTires() const;
	size_t getKilometers() const;
	size_t getWeight() const;;

	void drive(double km);

	const FuelTank& getFuelTank() const;
};

Car* dragRace(Car* car1, Car* car2);