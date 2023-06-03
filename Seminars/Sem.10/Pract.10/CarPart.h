#pragma once

#include <ostream>

class CarPart {
private:
    unsigned indetificator = 0;
    char *proizvoditel = nullptr;
    char *description = nullptr;
public:
    CarPart() = default;

    CarPart(unsigned, const char *, const char *);

    CarPart(const CarPart &);

    CarPart &operator=(const CarPart &);

    ~CarPart();

    friend std::ostream &operator<<(std::ostream &, const CarPart &);

private:
    void free();

    void copyFrom(const CarPart &);

    void setProiz(const char *);

    void setIndet(unsigned i);

    void setDesc(const char *);
};


