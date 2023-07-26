#pragma once

#include "Player.h"

class Guest : public Player {
    unsigned minutesLeft;
public:
    explicit Guest(unsigned id, unsigned minutesToPlay = 60);

    unsigned getMinutesLeft() const;

    void decrementMinutes(unsigned amount = 1);

    bool levelUp() override;
};