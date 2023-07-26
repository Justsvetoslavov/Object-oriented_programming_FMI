#pragma once

#include <iostream>

class CarPart {
    unsigned id;
    char *manufacturer;
    char *description;

    void free();

    void copyFrom(const CarPart &other);

    void moveFrom(CarPart &&other);

protected:
    static void copy(char *dest, const char *src);

public:
    CarPart();

    CarPart(unsigned id, const char *manufacturer, const char *description);

    CarPart(const CarPart &other);

    CarPart(CarPart &&other) noexcept;

    CarPart &operator=(const CarPart &other);

    CarPart &operator=(CarPart &&other) noexcept;

    ~CarPart();

    unsigned getId() const;

    const char *getManufacturer() const;

    const char *getDescription() const;

    void setId(unsigned id);

    void setManufacturer(const char *manufacturer);

    void setDescription(const char *description);
};

std::ostream &operator<<(std::ostream &os, const CarPart &part);
