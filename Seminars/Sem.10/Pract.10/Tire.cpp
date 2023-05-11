#include "Tire.h"

Tire::Tire(size_t widthInMilimeters, size_t profile, size_t diametersInInches)
{
    setWidthInMilimeters(widthInMilimeters);
    setProfile(profile);
    setDiameterIninches(diameterInInches);
}

size_t Tire::getWidthInMilimeters() const
{
    return widthInMilimeters;
}

size_t Tire::getProfile() const {
    return profile;
}

size_t Tire::getDiameterInInches() const {
    return diameterInInches;
}

void Tire::setWidthInMilimeters(size_t value)
{
    if (value < MIN_WIDTH || value > MAX_WIDTH) throw std::runtime_error("invalid value");
    widthInMilimeters = value;
}

void Tire::setProfile(size_t value)
{
    if (value < MIN_PROFILE || value > MAX_PROFILE) throw std::runtime_error("invalid value");
    profile = value;
}

void Tire::setDiameterIninches(size_t value)
{
    if (value < MIN_DIAMETER || value > MAX_DIAMETER) throw std::runtime_error("invalid value");
    diameterInInches = value;
}

std::ostream& operator<<(std::ostream& os, const Tire& tire)
{
    operator<<(os, (CarPart&)tire);
    String output = " - " + String(tire.getWidthInMilimeters()) + "/" +
        String(tire.getProfile()) + "R" + String(tire.getDiameterInInches());
    os << output;
    return os;
}
