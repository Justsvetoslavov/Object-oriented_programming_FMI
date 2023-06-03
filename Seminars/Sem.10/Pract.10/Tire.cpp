#include "Tire.h"

Tire::Tire() = default;

const size_t Tire::getWidth() const
{
    return width;
}

const size_t Tire::getProfile() const
{
    return profile;
}

const size_t Tire::getInches() const
{
    return inches;
}

void Tire::setWidth(const size_t width)
{
    if (width < MIN_WIDTH_SIZE || width > MAX_WIDTH_SIZE)
    {
        std::cout << ERROR_MESSAGE << std::endl;
        return;
    }
    else
    {
        this->width = width;
    }
}

void Tire::setProfile(const size_t profile)
{
    if (profile < MIN_PROFILE_SIZE || profile > MAX_PROFILE_SIZE)
    {
        std::cout << ERROR_MESSAGE << std::endl;
        return;
    }
    else
    {
        this->profile = profile;
    }
}

void Tire::setInces(const size_t inches)
{
    if (inches < MIN_INCHES || inches > MAX_INCHES)
    {
        std::cout << ERROR_MESSAGE << std::endl;
        return;
    }
    else
    {
        this->inches = inches;
    }
}

std::ostream& operator<<(std::ostream& stream, const Tire& tire)
{
    return stream << (CarPart&)tire;
    return stream << tire.width << " / " << tire.profile << " R " << tire.inches << std::endl;
}