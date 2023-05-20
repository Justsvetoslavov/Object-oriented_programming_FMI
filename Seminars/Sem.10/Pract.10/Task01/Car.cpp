#include "Car.h"

Car::Car(const FuelTank& tank, const Engine& engine, const Wheel* wheels, const Accumulator& accumulator, double kilometers, double weight)
{
	this->tank = tank;
	this->engine = engine;
	for (int i = 0; i < 4; i++) {
		this->wheels[i] = wheels[i];
	}
	this->accumulator = accumulator;
	this->kilometers = kilometers;
	this->weight = weight;
}

const FuelTank& Car::GetFuelTank() const {
	return tank;
}

double Car::GetWeight() const {
	return weight;
}

const Engine& Car::GetEngine() const {
	return engine;
}

void Car::Drive(double km) {
	if (km < 0)
		throw std::invalid_argument("The kilometers can't be a negative number!");

	if (tank.GetFullness() - km >= 0) {
		kilometers += km;
		tank.Use(km);
	}
}

Car* DragRace(Car* car1, Car* car2) {
	if (car1->GetFuelTank().GetFullness() >= 0.4) {
		if (car2->GetFuelTank().GetFullness() < 0.4)
			return car1;
		else {
			double ratio1 = car1->GetWeight() / car1->GetEngine().GetHorsePower();
			double ratio2 = car2->GetWeight() / car2->GetEngine().GetHorsePower();
			if (ratio1 >= ratio2)
				return car1;
			else
				return car2;
		}
	}
	else {
		if (car2->GetFuelTank().GetFullness() >= 0.4)
			return car2;
		else
			return nullptr;
	}
}
