#pragma once
#include <fstream>
#include "../Game/Game.h"

class GamePlatform {
    Game *games;
    size_t size;
public:

    GamePlatform();

    size_t getSize() const;

    bool addGame(Game game);
    void showGames();
    void showGameByID(const int &index);
    void showCheapestGame();
    void showMostExpensiveGame();
    void showFreeGames();
    void deleteByID(const int &index);
    int getGameID(const Game &game);

    bool readGamePlatform();
    bool savePlatform();

    virtual ~GamePlatform();



};
