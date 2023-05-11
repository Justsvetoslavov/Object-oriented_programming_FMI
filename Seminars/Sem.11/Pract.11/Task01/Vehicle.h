#pragma once
#include "Tire.h"
#include "Point.h"

enum class EngineType
{
    benzin,
    diesel,
    electric,
    noEngine,
};

enum class AllowedRoute
{
    city,
    highway,
    countryside,
    everywhere,
};

class Vehicle
{
    Tire *_tires = nullptr;
    double _averageSpeed = 0;
    EngineType _engineType = EngineType::noEngine;
    unsigned _tiresCount = 0;
    unsigned _passengerCount = 0;

public:
    Vehicle(const Tire *, double, EngineType, unsigned, unsigned);
    Vehicle(const Vehicle &);
    Vehicle &operator=(const Vehicle &);
    virtual ~Vehicle();

    void changeEngineType(EngineType);
    void changeTire(const Tire &, unsigned);
    double travelTime(const Point &, const Point &) const;

    virtual void allowedRouteOn() const = 0;

private:
    void free();
    void copyFrom(const Vehicle &);
    void copyTires(const Tire *, unsigned);
};