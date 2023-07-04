#pragma once

#include "../CarPart/Tires/Tires.h"
#include <cmath>

enum class EngineType {
    gas,
    electric,
    diesel,
    hydrogen,
    none
};

class Vehicle {
public:
    struct Point {
    private:
        int x, y;
    public:
        Point() = default;

        Point(int x, int y);

        double getDist(const Point& a) const;
    };

private:
    Tires *tires;
    unsigned countTires;
    EngineType type;
    unsigned countPassengers;
    double averageSpeed;

    void free();

    void copyFrom(const Vehicle &vehicle);

public:
    Vehicle();

    Vehicle(const Tires *_tires, unsigned countT, const EngineType &_type, unsigned countP, double averageS);

    Vehicle(const Vehicle &vehicle);

    virtual ~Vehicle();

    Vehicle &operator=(const Vehicle &vehicle);

    double findTime(const Point &a, const Point &b) const;

    void changeTire(const Tires &tire, unsigned index);

    virtual void GetPermit() const = 0;
};
