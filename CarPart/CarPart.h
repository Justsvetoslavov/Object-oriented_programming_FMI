#pragma once
#include <cstring>
#include <iostream>

class CarPart {
    unsigned int id;
    char* manufacture;
    char* description;

    void free();
    void copyFrom(const CarPart& part);
    void moveFrom(CarPart&& part);

public:

    CarPart();
    CarPart(int id, const char* name, const char* description);
    CarPart(const CarPart& part);
    CarPart& operator=(const CarPart& part);
    CarPart(CarPart&& part);
    CarPart& operator=(CarPart&& part);
    ~CarPart();
    friend std::ostream& operator<<(std::ostream& os, const CarPart& part);
};
