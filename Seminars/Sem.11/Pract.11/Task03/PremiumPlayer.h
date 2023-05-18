#ifndef PREMIUMPLAYER_H
#define PREMIUMPLAYER_H

#include "Player.h"

class PremiumPlayer : public Player
{
    char* m_name;
public:
    PremiumPlayer(const char* name);

    bool LevelUp() override;
};


#endif
