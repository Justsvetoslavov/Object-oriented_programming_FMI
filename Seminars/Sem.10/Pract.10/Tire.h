#pragma once
#include <iostream>
#include "CarPart.h"

const int MIN_WIDTH_SIZE = 155;
const int MAX_WIDTH_SIZE = 365;

const int MIN_PROFILE_SIZE = 30;
const int MAX_PROFILE_SIZE = 80;

const int MIN_INCHES = 13;
const int MAX_INCHES = 21;

class Tire : public CarPart
{
    size_t width = 0;
    size_t profile = 0;
    size_t inches = 0;

public:

    Tire();

    const size_t getWidth() const;

    const size_t getProfile() const;

    const size_t getInches() const;

    void setWidth(const size_t width);

    void setProfile(const size_t profile);

    void setInces(const size_t inches);

    friend std::ostream& operator<<(std::ostream& stream, const Tire& tire);
};
