#include "Car.h"

// The number of tires for Car is always 4. 
// For this reason, it's not a parameter in the Car(...) constructor
Car::Car(const Tire* tires, const EngineType& engineType, unsigned numberOfPassengers, double averageSpeed)
	: Vehicle(tires, CAR_TIRES_COUNT, engineType, numberOfPassengers, averageSpeed){

}

// Override
TravelRights Car::getTravelRights() {
	return CAR_TRAVEL_RIGHTS;
}
