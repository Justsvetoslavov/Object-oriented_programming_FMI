#include "Car.h"

#include "insufficient_fuel_error.h"

const int LITERS_PER_KM = 1;

Car::Car(const FuelTank& fuelTank, const Engine& engine, const Tire tires[4], const CarBattery& carBattery, double mileage, unsigned weight) : _fuelTank(fuelTank), _engine(engine), _carBattery(carBattery){
	for (int i = 0; i < 4; i++) {
		_tires[i] = tires[i];
	}

	_mileage = mileage;
	_weight = weight;
}

const FuelTank& Car::getFuelTank() const{
	return _fuelTank;
}

bool Car::drive(double km) {
	if (km <= 0) {
		return false;
	}

	try{
		_fuelTank.use(km * LITERS_PER_KM);
	}
	catch (insufficient_fuel_error& e) {
		std::cout << e.what() << std::endl;
		return false;
	}

	_mileage += km;
	return true;
}

const double DRAG_RACE_DIST = 0.4;

Car* dragRace(Car* car1, Car* car2) {
	bool drive1 = car1->drive(DRAG_RACE_DIST);
	bool drive2 = car2->drive(DRAG_RACE_DIST);

	if (drive1 == drive2 && drive1 == false) {
		return nullptr;
	}

	if (drive1 != drive2) {
		return drive1 == true ? car1 : car2;
	}

	double ratio1 = car1->_weight / car1->_engine.getHorsepower();
	double ratio2 = car2->_weight / car2->_engine.getHorsepower();

	return ratio1 > ratio2 ? car1 : car2;
}

void Car::fillTank(double toFill) {
	_fuelTank.fill(toFill);
}

double Car::getMileage() const {
	return _mileage;
}