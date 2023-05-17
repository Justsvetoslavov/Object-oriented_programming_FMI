#pragma once

#include "Vehicle.h"

const short BIKE_TIRES_COUNT = 2;
const TravelRights BIKE_TRAVEL_RIGHTS = TravelRights::city;

class Bike : Vehicle {
public:
	Bike() = default;
	Bike(const Tire* tires, double averageSpeed);
	TravelRights getTravelRights() override;
};