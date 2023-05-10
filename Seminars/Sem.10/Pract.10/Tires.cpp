#include "CarPart.h"
#include "Tires.h"
#include <iostream>
#pragma warning (disable : 4996)

Tires::Tires(unsigned id, char* manufacturer, char* description, unsigned width, unsigned profil, unsigned rimSize) :CarPart(id, manufacturer, description)
{
    setWidth(width);
    setProfil(profil);
    setRimSize(rimSize);
}

unsigned Tires::getWidth() const
{
    return width;
}

unsigned Tires::getProfil() const
{
    return profil;
}

unsigned Tires::getRimSize() const
{
    return rimSize;
}

void Tires::setWidth(unsigned width)
{
    if (width < 155 && width > 365 || this->width == width)
    {
        return;
    }
    this->width = width;
}

void Tires::setProfil(unsigned profil)
{
    if (profil < 30 && profil > 80 || this->profil == profil)
    {
        return;
    }
    this->profil = profil;
}

void Tires::setRimSize(unsigned rimSize)
{
    if (rimSize < 13 && rimSize > 21 || this->rimSize == rimSize)
    {
        return;
    }
    this->rimSize = rimSize;
}

std::ostream& operator<<(std::ostream& os, const Tires& tires)
{
    os << (CarPart&)tires << tires.getWidth() << "/" << tires.getProfil() << "R" << tires.getRimSize();

    return os;
}