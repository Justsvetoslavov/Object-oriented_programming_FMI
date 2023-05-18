#ifndef GUEST_H
#define GUEST_H


#include "Player.h"

class Guest : public Player
{
    int m_timeLeft;
public:
    Guest();

    bool LevelUp() override;
};


#endif
