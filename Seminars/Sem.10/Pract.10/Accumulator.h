#pragma once

#include "CarPart.h"
#include <ostream>

class Accumulator : private CarPart {
private:
    unsigned capacity = 0;
    char *batteryId = nullptr;
public:
    Accumulator() = default;

    Accumulator(unsigned, const char *, unsigned, const char *, const char *);

    Accumulator(const Accumulator &);

    Accumulator &operator=(const Accumulator &);

    ~Accumulator();

    friend std::ostream &operator<<(std::ostream &, const Accumulator &);

private:
    void free();

    void copyFrom(const Accumulator &);

    void setCapacity(unsigned);

    void setBatteryId(const char *);

};
