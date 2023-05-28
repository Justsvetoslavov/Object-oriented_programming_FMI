#include "Autobus.h"
#include <iostream>

Autobus::Autobus(const Tire *tires, double averageSpeed, EngineType engineType, unsigned tiresCount, unsigned passengerCount) : Vehicle(tires, averageSpeed, engineType, tiresCount, passengerCount)
{
}

void Autobus::allowedRouteOn() const
{
    std::cout << "AutoBus is allowed to drive in city and countryside";
}
