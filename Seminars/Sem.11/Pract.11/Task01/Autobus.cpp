#include "Autobus.h"

Autobus::Autobus(const Tire* tires, unsigned numberOfTires, const EngineType& engineType, unsigned numberOfPassengers, double averageSpeed)
	: Vehicle(tires, numberOfTires, engineType, numberOfPassengers, averageSpeed) {

}

TravelRights Autobus::getTravelRights() {
	return AUTOBUS_TRAVEL_RIGHTS;
}

