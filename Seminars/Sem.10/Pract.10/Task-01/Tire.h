#pragma once

#include "CarPart.h"

class Tire : public CarPart {
    short width;
    short profile;
    short diameter;

public:
    static const short MIN_WIDTH;
    static const short MAX_WIDTH;

    static const short MIN_PROFILE;
    static const short MAX_PROFILE;

    static const short MIN_DIAMETER;
    static const short MAX_DIAMETER;

    Tire(short width, short profile, short diameter);

    short getWidth() const;

    short getProfile() const;

    short getDiameter() const;

    void setWidth(short width);

    void setProfile(short profile);

    void setDiameter(short diameter);
};

std::ostream &operator<<(std::ostream &os, const Tire &tire);