#ifndef PRACT010_TYRE_H
#define PRACT010_TYRE_H
#include "CarPart.h"

class Tyre: CarPart {
    unsigned width;
    unsigned profile;
    unsigned diameter;

public:
    Tyre();
    Tyre(unsigned id, const MyString& name, const MyString& desc,
         unsigned width, unsigned profile, unsigned diameter);

    void setWidth(unsigned width);
    void setProfile(unsigned profile);
    void setDiameter(unsigned diam);

    unsigned int getWidth() const;

    unsigned int getProfile() const;

    unsigned int getDiameter() const;

    friend std::ostream & operator<<(std::ostream&os, const Tyre& tyre);
};
std::ostream & operator<<(std::ostream&os, const Tyre& tyre);


#endif //PRACT010_TYRE_H
