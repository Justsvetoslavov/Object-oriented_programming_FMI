#include <iostream>
#include <fstream>
#include "GamePlatform.hpp"

using std::cin, std::cout, std::endl, std::ifstream, std::ofstream;

GamePlatform::GamePlatform() {
    gamesCount = 0;
}

GamePlatform::GamePlatform(const Game *games, size_t gamesCount) {
    setGames(games, gamesCount);
}

const Game *GamePlatform::getGames() const {
    return games;
}

void GamePlatform::setGames(const Game *games, size_t gamesCount) {
    if (gamesCount > 100) {
        cout << "Too many games!" << endl;
        return;
    }
    for (int i = 0; i < gamesCount; ++i) {
        this->games[i] = games[i];
    }
    this->gamesCount = gamesCount;
}

size_t GamePlatform::getGamesCount() const {
    return gamesCount;
}

void GamePlatform::setGamesCount(size_t gamesCount) {
    if (gamesCount > 100) {
        cout << "Too many games!" << endl;
        return;
    }
    this->gamesCount = gamesCount;
}

void GamePlatform::addGame(const Game &game) {
    if (gamesCount == 100) {
        cout << "Too many games!" << endl;
        return;
    }
    games[gamesCount] = game;
    gamesCount++;
}

const Game GamePlatform::getGameByIndex(const int index) const {
    if (index < 0 || index >= gamesCount) {
        cout << "Invalid index!" << endl;
        return Game();
    }
    return games[index];
}

const Game GamePlatform::getTheMostExpensiveGame() const {
    if (gamesCount == 0) {
        cout << "No games!" << endl;
        return Game();
    }
    Game mostExpensiveGame = games[0];
    for (int i = 1; i < gamesCount; ++i) {
        if (games[i].getPrice() > mostExpensiveGame.getPrice()) {
            mostExpensiveGame = games[i];
        }
    }
    return mostExpensiveGame;
}

const Game GamePlatform::getTheCheapestGame() const {
    if (gamesCount == 0) {
        cout << "No games!" << endl;
        return Game();
    }
    Game cheapestGame = games[0];
    for (int i = 1; i < gamesCount; ++i) {
        if (games[i].getPrice() < cheapestGame.getPrice()) {
            cheapestGame = games[i];
        }
    }
    return cheapestGame;
}

void GamePlatform::printFreeGames() const {
    if (gamesCount == 0) {
        cout << "No games!" << endl;
        return;
    }
    for (int i = 0; i < gamesCount; ++i) {
        if (games[i].isFree()) {
            games[i].print();
        }
    }
}

void GamePlatform::removeGame(const char *title) {
    if (gamesCount == 0) {
        cout << "No games!" << endl;
        return;
    }
    for (int i = 0; i < gamesCount; ++i) {
        if (strcmp(games[i].getTitle(), title) == 0) {
            for (int j = i; j < gamesCount - 1; ++j) {
                games[j] = games[j + 1];
            }
            gamesCount--;
            return;
        }
    }
    cout << "No game with this title!" << endl;
}

void GamePlatform::writeToFile(const char *fileName) const {
    std::ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Cannot open file!" << endl;
        return;
    }
    file << gamesCount << endl;
    for (int i = 0; i < gamesCount; ++i) {
        file << games[i].getTitle() << endl;
        file << games[i].getPrice() << endl;
        file << games[i].getIsAvailable() << endl;
    }
    file.close();
}

void GamePlatform::readFromFile(const char *fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Cannot open file!" << endl;
        return;
    }
    file >> gamesCount;
    for (int i = 0; i < gamesCount; ++i) {
        file.ignore();
        char title[MAX_TITLE_LENGTH + 1];
        file.getline(title, MAX_TITLE_LENGTH + 1);
        games[i].setTitle(title);
        float price;
        file >> price;
        games[i].setPrice(price);
        bool isAvailable;
        file >> isAvailable;
        games[i].setIsAvailable(isAvailable);
    }
    file.close();
}