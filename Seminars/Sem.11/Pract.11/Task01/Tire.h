#pragma once
#include "Part.h"
#include <ostream>

class Tire : Part
{
    unsigned short _width = 0;
    unsigned short _profile = 0;
    unsigned short _diameter = 0;

public:
    Tire() = default;
    Tire(unsigned int, const char *, const char *, unsigned short, unsigned short, unsigned short);

    friend std::ostream &operator<<(std::ostream &, const Tire &);

private:
    static inline bool isWidthValid(unsigned int);
    static inline bool isProfileValid(unsigned int);
    static inline bool isDiameterValid(unsigned int);
};