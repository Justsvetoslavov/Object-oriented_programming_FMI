#pragma once

#include "Player.h"

class Guest : public Player {
private:
    int timeLeft;
public:
    Guest(unsigned, unsigned);

    bool levelUp() override final;

    unsigned getTimeLeft() const;

    void decrementTime(unsigned) const;

    bool canPlay() const;

    void progressOnMission(Mission &) override;
};

