#include "CarPart.h"

const size_t CarPart::getId() const
{
    return id;
}

const MyString CarPart::getManufacturer() const
{
    return manufacturer;
}

const MyString CarPart::getDescription() const
{
    return description;
}

void CarPart::setId(const size_t id)
{
    this->id = id;
}

void CarPart::setManufacturer(const MyString& manufacturer)
{
    this->manufacturer = manufacturer;
}

void CarPart::setDescription(const MyString& description)
{
    this->description = description;
}

std::ostream& operator<<(std::ostream& stream, const CarPart& part)
{
    return stream << part.id << " by " << part.manufacturer << " - " << part.description << " - ";
}