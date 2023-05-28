#pragma once

#include "Mission.h"

enum class Stars {
    one = 8,
    two,
    three,
    four,
    five
};

class Player {
protected:
    unsigned id;
    unsigned points;
    Stars stars;

    virtual unsigned getPointsNeeded() const;

public:
    Player(unsigned);

    virtual bool levelUp();

    virtual void progressOnMission(Mission &);
};


