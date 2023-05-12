#include "FuelTank.h"
#include <sstream>
#include "insufficient_fuel_error.h"

FuelTank::FuelTank(unsigned capacity) {
	SetCapacity(capacity);
	this->currentFullness = capacity;
}
void FuelTank::Use(double toUse) {
	if (toUse <= 0)
		throw std::invalid_argument("Usage of fuel should be more than 0!");
	if ((this->currentFullness - toUse) < 0)
		throw insufficient_fuel_error("Not enough fuel to be used!");

	this->currentFullness -= toUse;
}

void FuelTank::Fill(double toFill) {
	if (toFill <= 0)
		throw std::invalid_argument("Usage of fuel should be more than 0!");
	if ((this->currentFullness + toFill) >= this->capacity)
		this->currentFullness = this->capacity;

	this->currentFullness += toFill;
}

void FuelTank::SetCapacity(double capacity) {
	if (capacity < 0)
		throw std::invalid_argument("Capacity should be at least 0!");
	this->capacity = capacity;
}

double FuelTank::GetCurrentFullnes() const {
	return this->currentFullness;
}