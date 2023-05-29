#include "Car.h"

Car::Car(const Engine& engine, const Tire* tires, const Accumulator& accumulator, size_t killometers, size_t weight, size_t tankCapacity)
{
	this->engine = engine;
	for (size_t i = 0; i < 4; i++) this->tires[i] = tires[i];
	this->accumulator = accumulator;
	this->kilometers = killometers;
	this->weight = weight;
	this->tank = FuelTank(tankCapacity);
}

const Engine& Car::getEngine() const
{
	return engine;
}

const Accumulator& Car::getAccumulator() const
{
	return accumulator;
}

const Tire* Car::getTires() const
{
	return tires;
}

size_t Car::getKilometers() const
{
	return kilometers;
}

size_t Car::getWeight() const
{
	return weight;
}

void Car::drive(double km)
{
	if (km > tank.GetCurrentAmount()) return;
	kilometers += km;
	tank.use(km);
}

const FuelTank& Car::getFuelTank() const
{
	return tank;
}

Car* dragRace(Car* car1, Car* car2)
{
	if (car1 == nullptr || car2 == nullptr) return nullptr;
	if (car1->getFuelTank().GetCurrentAmount() < 0.4 &&
		car2->getFuelTank().GetCurrentAmount() < 0.4) return nullptr;
	if (car1->getFuelTank().GetCurrentAmount() < 0.4) return car2;
	if (car2->getFuelTank().GetCurrentAmount() < 0.4) return car1;
	double car1Power = (double)car1->getEngine().getHorsePower() / car1->getWeight();
	double car2Power = (double)car2->getEngine().getHorsePower() / car2->getWeight();
	if (car1Power > car2Power) return car1;
	else if (car2Power > car1Power) return car2;
	else return nullptr;
}

