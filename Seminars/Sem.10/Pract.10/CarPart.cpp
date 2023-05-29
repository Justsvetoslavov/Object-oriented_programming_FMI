#include "CarPart.h"

size_t CarPart::nextId = 1;

size_t CarPart::GetNextId()
{
    return nextId++;
}

size_t CarPart::getId() const
{
    return id;
}

const String& CarPart::getManifacturerName() const
{
    return manifacturerName;
}

const String& CarPart::getDescription() const
{
    return description;
}

void CarPart::SetManifacturerName(const String& name)
{
    manifacturerName = name;
}

void CarPart::SetDescription(const String& desc)
{
    description = desc;
}

std::ostream& operator<<(std::ostream& os, const CarPart& carPart)
{
    String output = "(" + String(carPart.getId()) + ") by " + carPart.getManifacturerName() +
        " - " + carPart.getDescription();
    os << output;
    return os;
}
