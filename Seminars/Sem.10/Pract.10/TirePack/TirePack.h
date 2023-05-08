#pragma once
#include "../CarPart/Tier/Tier.h"
#include "../CarPart/CarPart.h"
class TirePack{

    Tier* tires;
    unsigned short amount;

    void free();
    void copyFrom(const TirePack& other);
public:

    TirePack(const unsigned short amount);
    TirePack(const TirePack& other);
    TirePack(TirePack&& other);
    Tier& at(const unsigned short index);
    ~TirePack();

    void setTiersTo(const Tier& tier);

    TirePack& operator=(const TirePack& other);

    bool operator==(const TirePack &rhs) const;

    bool operator!=(const TirePack &rhs) const;
};
