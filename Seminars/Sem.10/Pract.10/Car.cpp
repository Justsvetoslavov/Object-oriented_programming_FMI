#include "Car.h"
#include "CarPart.h"
#include "Accumulator.h"
#include "Engine.h"
#include "FuelTank.h"
#include "Tires.h"
#pragma warning (disable : 4996)

Car::Car(FuelTank fuelTank, Engine* engine, Tires* tires[], Accumulator* accumulator, unsigned kilometers, unsigned weight, size_t counter)
{
	setAccumulator(accumulator);
	setFuelTank(fuelTank);
	setEngine(engine);
	setTires(tires, counter);
	setKilometers(kilometers);
	setWeight(weight);
}

const FuelTank& Car::getFuelTank()
{
	return fuelTank;
}

Engine* Car::getEngine()const
{
	return engine;
}

Tires* Car::getTires()const
{
	return *tires;
}

Accumulator* Car::getAccumulator()const
{
	return accumulator;
}

unsigned Car::getKilometers()const
{
	return kilometers;
}

unsigned Car::getWeight()const
{
	return weight;
}

void Car::setFuelTank(const FuelTank& fuelTank)
{
	this->fuelTank = fuelTank;
}

void Car::setEngine(Engine* engine)
{
	this->engine = engine;
}
void Car::setTires(Tires* tires[], size_t counter)
{
	for (size_t i = 0; i < counter; i++)
	{
		this->tires[i] = tires[i];
	}
}
void Car::setAccumulator(Accumulator*)
{
	this->accumulator = accumulator;
}
void Car::setKilometers(unsigned kilometers)
{
	this->kilometers = kilometers;
}
void Car::setWeight(unsigned weight)
{
	this->weight = weight;
}

void Car::drive(double km)
{
	this->fuelTank.use(km);
	this->kilometers += km;
}

Car* dragRace(Car* car1, Car* car2)
{
	static double distance = 0.4;
	unsigned tmp1 = car1->getKilometers();
	unsigned tmp2 = car2->getKilometers();
	try {
			car1->drive(distance);
	}
	catch (insufficient_fuel_error& e) {
		if (tmp1 == car1->getKilometers()) {
			return car2;
		}
		else {
			return nullptr;
		}
	}
	try {
		car2->drive(distance);
	}
	catch (insufficient_fuel_error& e) {
		if (tmp2 == car2->getKilometers()) {
			return car1;
		}
		else {
			return nullptr;
		}
	}
	double ratio1 = car1->getWeight() / car1->getEngine()->getHorsepower();
	double ratio2 = car2->getWeight() / car2->getEngine()->getHorsepower();
	if (ratio1 > ratio2) {
		return car1;
	}
	else {
		return car2;
	}
}
