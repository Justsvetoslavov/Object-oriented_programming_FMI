#pragma once

#include "CarPart.h"

class Accumulator : public CarPart {
    double capacity;
    char *batteryId;

    void free();

    void copyFrom(const Accumulator &other);

    void moveFrom(Accumulator &&other);

public:
    Accumulator();

    Accumulator(double capacity, const char *batteryId);

    Accumulator(const Accumulator &other);

    Accumulator(Accumulator &&other) noexcept;

    Accumulator &operator=(const Accumulator &other);

    Accumulator &operator=(Accumulator &&other) noexcept;

    ~Accumulator();

    double getCapacity() const;

    const char *getBatteryId() const;

    void setCapacity(double capacity);

    void setBatteryId(const char *batteryId);
};

std::ostream &operator<<(std::ostream &os, const Accumulator &accumulator);