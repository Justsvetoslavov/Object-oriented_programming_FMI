#pragma once

#include "Stars.h"


class Player {
protected:
    unsigned id;
    unsigned points;
    Stars stars;

    bool upgrade(unsigned required);

public:
    explicit Player(unsigned id);

    unsigned getId() const;

    unsigned getPoints() const;

    Stars getStars() const;

    void setPoints(unsigned newPoints);

    void addPoints(unsigned amount);

    void removePoints(unsigned amount);

    virtual bool levelUp();
};