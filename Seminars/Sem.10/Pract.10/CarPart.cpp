#include "CarPart.h"
#include <iostream>
#pragma warning (disable : 4996)

CarPart::CarPart()
{
    id = 0;
    manufacturer = nullptr;
    description = nullptr;
}

CarPart::CarPart(unsigned id, char* name, char* description)
{
    setId(id);
    setName(name);
    setDescription(description);
}

CarPart::CarPart(const CarPart& other)
{
    copyFrom(other);
}

CarPart& CarPart::operator=(const CarPart&other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

CarPart::~CarPart()
{
    free();
}

unsigned CarPart::getId() const
{
    return id;
}

char* CarPart::getName() const
{
    return manufacturer;
}

char* CarPart::getDescription() const
{
    return description;
}

void CarPart::setId(unsigned id)
{
    this->id = id;
}

void CarPart::setName(char* manufacturer)
{
    if (manufacturer == nullptr || strlen(manufacturer) == 0 || this->manufacturer == manufacturer)
        return;
    delete[] this->manufacturer;
    this->manufacturer = new char[strlen(manufacturer) + 1];
    strcpy(this->manufacturer, manufacturer);
}

void CarPart::setDescription(char* description)
{
    if (description == nullptr || strlen(description) == 0 || this->description == description)
        return;
    delete[] this->description;
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

void CarPart::copyFrom(const CarPart& other)
{
    id = other.id;
    this->manufacturer = new char[strlen(other.manufacturer) + 1];
    strcpy(this->manufacturer, manufacturer);
    try
    {
        this->description = new char[strlen(other.description) + 1];
        strcpy(this->description, other.description);
    }
    catch(std::bad_alloc)
    {
        delete[] this->manufacturer;
        throw;
    }
}

void CarPart::free()
{
    delete[] manufacturer;
    delete[] description;
}

std::ostream& operator<<(std::ostream& os, const CarPart& carPart)
{
    os << carPart.getId() << "by" << carPart.getName() << " - " << carPart.getDescription() << " - ";

    return os;
}






