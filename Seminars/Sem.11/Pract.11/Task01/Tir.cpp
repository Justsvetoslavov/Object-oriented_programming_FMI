#include "Tir.h"

Tir::Tir(const Tire* tires, unsigned numberOfTires, const EngineType& engineType, unsigned numberOfPassengers, double averageSpeed)
	: Vehicle(tires, numberOfTires, engineType, numberOfPassengers, averageSpeed) {

}

TravelRights Tir::getTravelRights() {
	return TIR_TRAVEL_RIGHTS;
}