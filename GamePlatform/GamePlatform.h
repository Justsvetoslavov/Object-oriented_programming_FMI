#pragma once

#include "../Game/Game.h"
#include <fstream>

const int MAX_GAMES = 20;
const int MAX_SYMBOLS = 1024;
const char PATH[MAX_SYMBOLS] = "test.txt";

class GamePlatform {
    Game games[MAX_GAMES];
    int size = 0;

public:
    void addGame(const char *title, float price, bool isAvailable);

    void readByIndex(int index) const;

    void readAll() const;

    void readMinMaxPriceGame() const;

    void readFree() const;

    void deleteByIndex(int index);

    void writeToFile() const;

    Game readGame(std::fstream &file);

    void readFromFile();
};
