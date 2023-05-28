#include "Bike.h"
#include <iostream>

Bike::Bike(const Tire *tires, double averageSpeed, EngineType engineType, unsigned tiresCount, unsigned passengerCount) : Vehicle(tires, averageSpeed, engineType, tiresCount, passengerCount)
{
}

void Bike::allowedRouteOn() const
{
    std::cout << "Bike is allowed to drive in city and countryside";
}