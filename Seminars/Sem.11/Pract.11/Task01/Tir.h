#pragma once

#include "Vehicle.h"

const TravelRights TIR_TRAVEL_RIGHTS = TravelRights::highways;

class Tir : Vehicle{
	Tir() = default;
	// Different kinds of trucks have different numbers of wheels
	Tir(const Tire* tires, unsigned numberOfTires, const EngineType& engineType, unsigned numberOfPassengers, double averageSpeed);
	TravelRights getTravelRights() override;
};