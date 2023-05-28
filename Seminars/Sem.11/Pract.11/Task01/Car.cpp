#include "Car.h"
#include <iostream>

Car::Car(const Tire *tires, double averageSpeed, EngineType engineType, unsigned tiresCount, unsigned passengerCount) : Vehicle(tires, averageSpeed, engineType, tiresCount, passengerCount)
{
}

void Car::allowedRouteOn() const
{
    std::cout << "Car is allowed to drive everywhere";
}
