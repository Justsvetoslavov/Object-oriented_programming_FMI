#pragma once
#include "../CarPart.h"

class Tires : CarPart{
    int width = 0;
    int profile = 0;
    int diameter = 0;

public:
    Tires() = default;
    Tires(int id, const char *name, const char *description, int width, int profile, int diameter);
    friend std::ostream &operator<<(std::ostream& os, const Tires& tires);
};