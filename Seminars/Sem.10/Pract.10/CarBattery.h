#pragma once
#include <iostream>
#include "CarPart.h"

class CarBattery : public CarPart
{
    size_t capacity = 0;
    MyString bateryId;

public:

    const size_t getCapacity() const;

    const MyString getBateryId() const;

    void setCapacity(const size_t capacity);

    void setBateryId(const MyString& bateryId);

    friend std::ostream& operator<<(std::ostream& stream, const CarBattery& accumulator);
};
