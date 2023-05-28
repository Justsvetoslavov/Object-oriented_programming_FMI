#include "Tire.h"
#include <stdexcept>

Tire::Tire(unsigned int ID, const char *manufacturer, const char *description, unsigned short width, unsigned short profile, unsigned short diameter) : Part(ID, manufacturer, description)
{

    if (!(isWidthValid(width) && isProfileValid(profile) && isDiameterValid(diameter)))
        throw std::invalid_argument("Invalid input data.");

    _width = width;
    _profile = profile;
    _diameter = diameter;
}

inline bool Tire::isWidthValid(unsigned int width)
{
    return (width >= 154 && width <= 365);
}

inline bool Tire::isProfileValid(unsigned int profile)
{
    return (profile >= 30 && profile <= 80);
}

inline bool Tire::isDiameterValid(unsigned int diameter)
{
    return (diameter >= 13 && diameter <= 21);
}

std::ostream &operator<<(std::ostream &out, const Tire &obj)
{
    return out << (const Part &)obj << " - "
               << obj._width << "/" << obj._profile << "R" << obj._diameter;
}