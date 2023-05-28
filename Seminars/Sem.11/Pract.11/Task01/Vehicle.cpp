#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(const Tire *tires, double averageSpeed, EngineType engineType, unsigned tiresCount, unsigned passengerCount)
{
    if (tiresCount == 0)
        throw std::invalid_argument("Invalid number of tires. Task terminated.");

    _averageSpeed = averageSpeed;
    _engineType = engineType;
    _tiresCount = tiresCount;
    _passengerCount = passengerCount;

    _tires = new Tire[tiresCount];

    for (unsigned i = 0; i < tiresCount; ++i)
        _tires[i] = _tires[i];
}

Vehicle::Vehicle(const Vehicle &other)
{
    copyFrom(other);
}

Vehicle &Vehicle::operator=(const Vehicle &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Vehicle::~Vehicle()
{
    free();
}

void Vehicle::changeEngineType(EngineType type)
{
    _engineType = type;
}

double Vehicle::travelTime(const Point &A, const Point &B) const
{
    return calculateDistance(A, B) * _averageSpeed;
}

void Vehicle::free()
{
    delete[] _tires;
    _tires = nullptr;
}

void Vehicle::copyFrom(const Vehicle &other)
{
}

void Vehicle::copyTires(const Tire *tires, unsigned tiresCount)
{
    _tires = new Tire[tiresCount];

    for (unsigned i = 0; i < tiresCount; ++i)
        _tires[i] = tires[i];
}

void Vehicle::changeTire(const Tire &tire, unsigned idx)
{
    if (idx >= _tiresCount)
        throw std::out_of_range("Invalid tire index");

    _tires[idx] = tire;
}
