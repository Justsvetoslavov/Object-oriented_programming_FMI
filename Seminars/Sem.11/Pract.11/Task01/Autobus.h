#pragma once
#include "Vehicle.h"

class Autobus : Vehicle
{
public:
    Autobus(const Tire *, double, EngineType, unsigned, unsigned);
    void allowedRouteOn() const override final;
};