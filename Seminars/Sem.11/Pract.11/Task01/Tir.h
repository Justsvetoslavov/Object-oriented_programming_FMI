#pragma once
#include "Vehicle.h"

class Tir : Vehicle
{
    Tir(const Tire *, double, EngineType, unsigned, unsigned);
    void allowedRouteOn() const override final;
};