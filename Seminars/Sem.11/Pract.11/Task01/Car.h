#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
public:
    Car(const Tire *, double, EngineType, unsigned, unsigned);
    void allowedRouteOn() const override final;
};