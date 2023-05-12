#include "Car.h"

const int DRAG_RACE_KM = 0.4;

Car::Car(const FuelTank& fuelTank, const Engine& engine, const Wheel* wheels,
	const Accumulator& accumulator, unsigned kilometers, double weight) {
	this->fuelTank = fuelTank;
	this->engine = engine;
	for (size_t i = 0; i < WHEELS_COUNT; i++)
	{
		this->wheels[i] = wheels[i];
	}
	this->accumulator = accumulator;
	this->kilometers = kilometers;
	this->weight = weight;
}

const FuelTank& Car::GetFuelTank() const {
	return this->fuelTank;
}

double Car::GetWeight() const {
	return this->weight;
}

void Car::Drive(double km) {
	if (km > fuelTank.GetCurrentFullnes())
		return;

	this->kilometers += km;
	try {
		this->fuelTank.Use(km);
	}
	catch (insufficient_fuel_error) {
		std::cout << "Not enough fuel to be used!";
	}
}

const Engine& Car::GetEngine() const {
	return this->engine;
}

Car* DragRace(Car* car1, Car* car2) {
	if (car1 == nullptr || car2 == nullptr)
		return nullptr;
	if (car1->GetFuelTank().GetCurrentFullnes() < DRAG_RACE_KM
		&& car2->GetFuelTank().GetCurrentFullnes() >= DRAG_RACE_KM)
		return car2;
	if (car1->GetFuelTank().GetCurrentFullnes() >= DRAG_RACE_KM
		&& car2->GetFuelTank().GetCurrentFullnes() < DRAG_RACE_KM)
		return car1;
	if (car1->GetFuelTank().GetCurrentFullnes() < DRAG_RACE_KM
		&& car2->GetFuelTank().GetCurrentFullnes() < DRAG_RACE_KM)
		return nullptr;

	double car1Stats = car1->GetWeight() / car1->GetEngine().GetHoursePower();
	double car2Stats = car2->GetWeight() / car2->GetEngine().GetHoursePower();
	if (car1Stats > car2Stats)
		return car1;
	else if (car2Stats > car1Stats)
		return car2;
	else
		return nullptr;
}