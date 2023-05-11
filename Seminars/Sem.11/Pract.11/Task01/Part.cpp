#include "Part.h"
#include <cstring>
#include <stdexcept>

Part::Part(unsigned int ID, const char *manufacturer, const char *description)
{
    if (!manufacturer || !description)
        throw std::invalid_argument("Invalid input data. Nullptr provided.");

    _ID = ID;

    _manufacturer = new char[strlen(manufacturer) + 1];
    strcpy(_manufacturer, manufacturer);

    _description = new char[strlen(description) + 1];
    strcpy(_description, description);
}

Part::Part(const Part &other)
{
    copyFrom(other);
}

Part &Part::operator=(const Part &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

void Part::copyFrom(const Part &other)
{
    _ID = other._ID;
    copyManufacturer(other._manufacturer);
    copyDescription(other._description);
}

void Part::copyManufacturer(const char *data)
{
    if (!data)
        throw std::invalid_argument("Invalid input data. Nullptr provided.");

    _manufacturer = new char[strlen(data) + 1];
    strcpy(_manufacturer, data);
}

void Part::copyDescription(const char *data)
{
    if (!data)
        throw std::invalid_argument("Invalid input data. Nullptr provided.");

    _description = new char[strlen(data) + 1];
    strcpy(_description, data);
}

void Part::free()
{
    delete[] _manufacturer;
    delete[] _description;
    _manufacturer = nullptr;
    _description = nullptr;
    _ID = 0;
}

std::ostream &operator<<(std::ostream &out, const Part &obj)
{
    return out << "(" << obj._ID << ")"
               << " by " << obj._manufacturer
               << " - " << obj._description;
}