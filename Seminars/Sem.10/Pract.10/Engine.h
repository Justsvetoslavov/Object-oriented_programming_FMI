#pragma once
#include <iostream>
#include "CarPart.h"

class Engine : public CarPart
{
    size_t horsePower = 0;

public:

    const size_t getHorsePower() const;

    void setHorsePower(const size_t horsePower);

    friend std::ostream& operator<<(std::ostream& stream, const Engine& engine);
};
