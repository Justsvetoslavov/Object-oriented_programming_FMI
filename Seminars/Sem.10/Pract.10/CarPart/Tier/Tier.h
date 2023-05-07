#pragma once
#include "../CarPart.h"

const unsigned short VALID_WIDTH = 200;
const unsigned short VALID_PROFILE = 70;
const unsigned short VALID_DIAMETER = 16;

class Tier: protected CarPart{

    unsigned short width = 0;
    unsigned short profile = 0;
    unsigned short diameter = 0;

    void copyFrom(const Tier& other);
    void isValid(unsigned short width,unsigned short profile,unsigned short diameter);

public:

    Tier();
    Tier(unsigned short width,unsigned short profile,unsigned short diameter,unsigned int id);
    Tier(unsigned short width,unsigned short profile,unsigned short diameter,
         unsigned int id,
         const char* brand,
         const char* description
         );

    Tier(const Tier& other);
    Tier(Tier&& other);


    const unsigned short getWidth() const;
    const unsigned short getProfile() const;
    const unsigned short getDiameter() const;

    Tier& setWidth(unsigned short _width);
    Tier& setProfile(unsigned short _profile);
    Tier& setDiameter(unsigned short _diameter);

    Tier& operator=(const Tier& other);

    friend std::ostream& operator<<(std::ostream& os,const Tier& tier);

};

