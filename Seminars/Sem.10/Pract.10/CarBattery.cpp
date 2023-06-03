#include "CarBattery.h"

const size_t CarBattery::getCapacity() const
{
    return capacity;
}

const MyString CarBattery::getBateryId() const
{
    return bateryId;
}

void CarBattery::setCapacity(const size_t capacity)
{
    if (capacity <= 0)
    {
        std::cout << ERROR_MESSAGE << std::endl;
        return;
    }
    else
    {
        this->capacity = capacity;
    }
}

void CarBattery::setBateryId(const MyString& bateryId)
{
    this->bateryId = bateryId;
}

std::ostream& operator<<(std::ostream& stream, const CarBattery& accumulator)
{
    return stream << (CarPart&)accumulator;
    return stream << accumulator.capacity << "Ah" << std::endl;
}