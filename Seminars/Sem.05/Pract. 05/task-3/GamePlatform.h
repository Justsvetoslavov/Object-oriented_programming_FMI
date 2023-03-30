#pragma once

#include "Game.h"

class GamePlatform {
private:
    Game *games;
    unsigned int size;
    unsigned int addedGames;

    void resizeGames();

public:
    const Game* getGames() const;

};