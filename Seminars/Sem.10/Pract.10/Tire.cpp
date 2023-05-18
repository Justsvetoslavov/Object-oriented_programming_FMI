//
// Created by Mihail Tsankov on 11.05.23.
//

#include "Tire.h"

Tire::Tire(unsigned int wideness, unsigned int profile, unsigned int diameter, unsigned int indetificator,
           const char *proizvoditel, const char *description) : CarPart(indetificator, proizvoditel, description) {
    setWideness(wideness);
    setProfile(profile);
    setDiameter(diameter);
}

void Tire::setWideness(unsigned int wideness) {
    if (wideness < 155 || wideness > 365) {
        return;
    }

    this->wideness = wideness;
}

void Tire::setProfile(unsigned int profile) {
    if (profile < 30 || profile > 80) {
        return;
    }

    this->profile = profile;
}

void Tire::setDiameter(unsigned int diameter) {
    if (diameter < 13 || diameter > 21) {
        return;
    }

    this->diameter = diameter;
}

std::ostream &operator<<(std::ostream &os, const Tire &tire) {
    os << (CarPart &) tire << " - " << tire.wideness << "/" << tire.profile << "R" << tire.diameter;
    return os;
}
