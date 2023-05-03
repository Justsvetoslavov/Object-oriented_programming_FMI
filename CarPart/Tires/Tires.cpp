#include "Tires.h"

Tires::Tires(int id, const char *name, const char *description, int width, int profile, int diameter) : CarPart(id, name, description) {
    if (width < 155 || width > 365 || profile > 80 || profile < 30 || diameter < 13 || diameter > 21)
        throw std::invalid_argument("Invalid input");
    this->width = width;
    this->diameter = diameter;
    this->profile = profile;
}

std::ostream &operator<<(std::ostream& os, const Tires& tires) {
    os << (CarPart)tires << " - " << tires.width << '/' << tires.profile << 'R' << tires.diameter;
}