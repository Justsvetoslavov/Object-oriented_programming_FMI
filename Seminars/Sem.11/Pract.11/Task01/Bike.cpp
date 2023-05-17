#include "Bike.h"

// The number of tires for Bike is constant(=2)
// Bike doesn't have an engine
// The number of passengers for Bike is 1 
// ** I am not taking tandem bikes or motorized bikes into account
Bike::Bike(const Tire* tires, double averageSpeed)
	: Vehicle(tires, BIKE_TIRES_COUNT, EngineType::none, 1, averageSpeed){

}

TravelRights Bike::getTravelRights() {
	return BIKE_TRAVEL_RIGHTS;
}