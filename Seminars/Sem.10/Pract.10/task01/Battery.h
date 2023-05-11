#ifndef PRACT010_BATTERY_H
#define PRACT010_BATTERY_H
#include "CarPart.h"
#include <iostream>

class Battery: CarPart {

    unsigned capacity;
    unsigned batteryId;
public:
    Battery(unsigned id, const MyString&name, const MyString& description,
            unsigned capacity, unsigned batteryId);

    unsigned int getCapacity() const;

    void setCapacity(unsigned int capacity);

    unsigned int getBatteryId() const;

    void setBatteryId(unsigned int id);

    friend std::ostream & operator<<(std::ostream&os, const Battery& bt);
};

std::ostream & operator<<(std::ostream&os, const Battery& bt);

#endif //PRACT010_BATTERY_H
