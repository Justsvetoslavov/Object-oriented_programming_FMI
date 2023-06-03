#pragma once

#include "CarPart.h"
#include <ostream>

class Engine : private CarPart {
private:
    unsigned horsePower = 0;
public:
    Engine() = default;

    Engine(unsigned, unsigned, const char *, const char *);

    friend std::ostream &operator<<(std::ostream &, const Engine &);

    unsigned getHorsePower() const;

private:
    void setHorsePower(unsigned);

};


