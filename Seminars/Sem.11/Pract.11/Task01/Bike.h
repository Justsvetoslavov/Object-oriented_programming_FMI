#pragma once
#include "Vehicle.h"

class Bike : Vehicle
{
public:
    Bike(const Tire *, double, EngineType, unsigned, unsigned);
    void allowedRouteOn() const override final;
};