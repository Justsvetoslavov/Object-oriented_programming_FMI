#include "Tire.h"

const short Tire::MIN_WIDTH = 155;
const short Tire::MAX_WIDTH = 365;

const short Tire::MIN_PROFILE = 30;
const short Tire::MAX_PROFILE = 80;

const short Tire::MIN_DIAMETER = 13;
const short Tire::MAX_DIAMETER = 21;

Tire::Tire(short width, short profile, short diameter) {
    setWidth(width);
    setProfile(profile);
    setDiameter(diameter);
}

short Tire::getWidth() const {
    return width;
}

short Tire::getProfile() const {
    return profile;
}

short Tire::getDiameter() const {
    return diameter;
}

void Tire::setWidth(short width) {
    if (width < MIN_WIDTH) {
        width = MIN_WIDTH;
    } else if (width > MAX_WIDTH) {
        width = MAX_WIDTH;
    }
    this->width = width;

}

void Tire::setProfile(short profile) {
    if (profile < MIN_PROFILE) {
        profile = MIN_PROFILE;
    } else if (profile > MAX_PROFILE) {
        profile = MAX_PROFILE;
    }
    this->profile = profile;
}

void Tire::setDiameter(short diameter) {
    if (diameter < MIN_DIAMETER) {
        diameter = MIN_DIAMETER;
    } else if (diameter > MAX_DIAMETER) {
        diameter = MAX_DIAMETER;
    }
    this->diameter = diameter;
}

std::ostream &operator<<(std::ostream &os, const Tire &tire) {
    return os << (CarPart &) tire << tire.getWidth() << '/'
              << tire.getProfile() << 'R' << tire.getDiameter();
}