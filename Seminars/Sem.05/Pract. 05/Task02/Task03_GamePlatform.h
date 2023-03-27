#pragma once
#include "Task03_Game.h"

class GamePlatform
{
    Game *games;
    int currentSize;
    int capacity;

public:
    GamePlatform();
    void add(const Game &);
    void remove(const Game &);
    void remove(const int idx);
    const Game &getGameAt(const int idx) const;
    Game *getAllGames() const;
    const Game &getCheapest() const;
    const Game &getMostExpensive() const;
    Game *getFreeGames() const;
    void saveToFile() const;
    void loadFromFile();
};
