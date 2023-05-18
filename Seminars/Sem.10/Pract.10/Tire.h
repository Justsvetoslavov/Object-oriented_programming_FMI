#pragma once

#include "CarPart.h"
#include <ostream>

class Tire : private CarPart {
private:
    unsigned wideness = 155;
    unsigned profile = 30;
    unsigned diameter = 13;
public:
    Tire() = default;

    Tire(unsigned, unsigned, unsigned, unsigned, const char *, const char *);

    friend std::ostream &operator<<(std::ostream &, const Tire &);

private:
    void setWideness(unsigned);

    void setProfile(unsigned);

    void setDiameter(unsigned);
};


