#include "Tir.h"
#include <iostream>

Tir::Tir(const Tire *tires, double averageSpeed, EngineType engineType, unsigned tiresCount, unsigned passengerCount) : Vehicle(tires, averageSpeed, engineType, tiresCount, passengerCount)
{
}

void Tir::allowedRouteOn() const
{
    std::cout << "Tir allowed to drive everywhere";
}