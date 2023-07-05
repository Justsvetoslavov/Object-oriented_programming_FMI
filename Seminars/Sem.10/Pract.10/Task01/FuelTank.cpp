#include "FuelTank.h"

#include "insufficient_fuel_error.h"

FuelTank::FuelTank(double capacity) {
	if (capacity <= 0) {
		_capacity = _fullness = 0;
		return;
	}

	_capacity = _fullness = capacity;
}

void FuelTank::use(double toUse) {
	if (toUse <= 0) {
		return;
	}

	if (toUse > _fullness) {
		throw insufficient_fuel_error();
	}

	_fullness -= toUse;
}

void FuelTank::fill(double toFill) {
	if (toFill <= 0) {
		return;
	}

	_fullness += toFill;
	if (_fullness > _capacity) {
		_fullness = _capacity;
	}
}