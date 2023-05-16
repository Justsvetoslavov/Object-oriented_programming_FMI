#include "FuelTank.h"
#include <sstream>

FuelTank::FuelTank(double capacity){
	if (capacity < 0)
		throw std::out_of_range("The capacity cannot be less than zero!");

	this->capacity = capacity;
	this->fullness = capacity;
}

void FuelTank::Use(double toUse){
	if (fullness - toUse < 0)
		throw insufficient_fuel_error("There is not enough fuel");

	fullness -= toUse;
}

void FuelTank::Fill(double ToFill){
	fullness += ToFill;
	if (fullness > capacity)
		fullness = capacity;
}

double FuelTank::GetFullness() const{
	return fullness;
}
