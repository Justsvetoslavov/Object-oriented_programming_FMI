#include "game.hpp"

class GamePlatform {
private:
    Game games[100];
    size_t gamesCount;

public:
    GamePlatform();

    GamePlatform(const Game *games, size_t gamesCount);

    const Game *getGames() const;

    void setGames(const Game *games, size_t gamesCount);

    size_t getGamesCount() const;

    void setGamesCount(size_t gamesCount);

    void addGame(const Game &game);

    const Game getGameByIndex(int index) const;

    const Game getTheMostExpensiveGame() const;

    const Game getTheCheapestGame() const;

    void printFreeGames() const;

    void removeGame(const char *title);

    void writeToFile(const char *fileName) const;

    void readFromFile(const char *fileName);

};
