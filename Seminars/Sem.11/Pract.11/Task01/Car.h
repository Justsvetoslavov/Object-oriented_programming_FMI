#pragma once

#include "Vehicle.h"

const short CAR_TIRES_COUNT = 4;
const TravelRights CAR_TRAVEL_RIGHTS = TravelRights::all;

class Car : public Vehicle {
public:
	Car() = default;
	Car(const Tire* tires, const EngineType& engineType, unsigned numberOfPassengers, double averageSpeed);
	TravelRights getTravelRights() override;
};