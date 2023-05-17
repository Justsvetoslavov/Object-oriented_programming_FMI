#pragma once

#include "Vehicle.h"

const TravelRights AUTOBUS_TRAVEL_RIGHTS = TravelRights::all;

class Autobus : Vehicle {
	Autobus() = default; 

	// Different kinds of buses have different numbers of wheels
	Autobus(const Tire* tires, unsigned numberOfTires, const EngineType& engineType, unsigned numberOfPassengers, double averageSpeed);
	TravelRights getTravelRights() override;
};