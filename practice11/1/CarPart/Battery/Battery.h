#pragma once
#include "../CarPart.h"

class Battery : CarPart{
    int capacity;
    char* batteryId;

    void free();
    void copyFrom(const Battery& battery);

public:
    Battery();
    Battery(const Battery& battery);
    Battery(int id, const char *name, const char *description, int capacity, const char *batteryId);
    Battery& operator=(const Battery& battery);
    ~Battery();
    friend std::ostream& operator<<(std::ostream& os, const Battery& battery);
};
