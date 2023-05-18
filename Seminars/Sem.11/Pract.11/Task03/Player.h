#ifndef PLAYER_H
#define PLAYER_H

#include <cstdint>
#include "PlayerStars.h"

class Player
{
    int m_id;
protected:
    size_t m_points;
    PlayerStars m_stars;
    explicit Player(int id);
public:
    Player();
    virtual ~Player() = default;

    void CompleteMission(size_t points);
    virtual bool LevelUp();
};


#endif
