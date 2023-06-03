#pragma once
#include "MyString.h"
#include <iostream>

const char ERROR_MESSAGE[] = "Invalid data!";

class CarPart
{
protected:

    size_t id = 0;
    MyString manufacturer;
    MyString description;

public:

    const size_t getId() const;

    const MyString getManufacturer() const;

    const MyString getDescription() const;

    void setId(const size_t id);

    void setManufacturer(const MyString& manufacturer);

    void setDescription(const MyString& description);

    friend std::ostream& operator<<(std::ostream& stream, const CarPart& part);
};