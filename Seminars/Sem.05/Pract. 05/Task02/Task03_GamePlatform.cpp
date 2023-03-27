#include <iostream>
#include <fstream>
#include "Task03_GamePlatform.h"
#include "Task03_Utils.h"

const int DEFAULT_GAME_CAPACITY = 16;
const char FILE_NAME[] = "platform.dat";
const char PLATFORM_NAME[] = "platform";
const int LINE_SIZE = 512;

GamePlatform::GamePlatform()
{
    currentSize = 0;
    capacity = DEFAULT_GAME_CAPACITY;
    this->games = new Game[DEFAULT_GAME_CAPACITY];
}

void GamePlatform::add(const Game &game)
{
    if (this->currentSize >= this->capacity)
    {
        this->capacity *= 2;
        resize(this->games, this->capacity, this->currentSize, true);
    }

    this->games[this->currentSize++] = game;
}

/*
Something is wrong with the remove method and i don't know what.
After calling it, when i try to create new GamePlatform object i get memory error on line 16.
Why is that? Thanks for the feedback.
*/
void GamePlatform::remove(const Game &game)
{
    if (!currentSize)
    {
        return;
    }

    for (int i = 0; i < this->currentSize; ++i)
    {
        if (myStrCmp(this->games[i].getTitle(), game.getTitle()) &&
            this->games[i].getPrice() == game.getPrice() &&
            this->games[i].getIsAvailable() == game.getIsAvailable())
        {
            this->games[i].~Game();
            this->games[i] = this->games[--currentSize];
        }
    }
}

void GamePlatform::remove(const int idx = 0)
{
    if (!this->currentSize || idx < 0 || idx >= this->currentSize)
    {
        return;
    }

    // move the last element where the "deleted" on is. When we add new element, we overwrite what was at the end.
    this->games[idx].~Game();
    this->games[idx] = games[--currentSize];
}

const Game &GamePlatform::getGameAt(const int idx) const
{
    return this->games[idx];
}

Game *GamePlatform::getAllGames() const
{
    return this->games;
}

const Game &GamePlatform::getCheapest() const
{
    int cheapestIdx = -1;
    int cheapest = INT_MAX;

    for (int i = 0; i < this->currentSize; ++i)
    {
        if (this->games[i].getPrice() < cheapest)
        {
            cheapestIdx = i;
            cheapest = this->games[i].getPrice();
        }
    }

    return this->games[cheapestIdx];
}

const Game &GamePlatform::getMostExpensive() const
{
    int mostExpensiveIdx = -1;
    int mostExpensive = INT_MIN;

    for (int i = 0; i < this->currentSize; ++i)
    {
        if (this->games[i].getPrice() > mostExpensive)
        {
            mostExpensiveIdx = i;
            mostExpensive = this->games[i].getPrice();
        }
    }

    return this->games[mostExpensiveIdx];
}

Game *GamePlatform::getFreeGames() const
{
    Game *freeGames = new Game[this->currentSize];
    int writeIdx = 0;

    for (int i = 0; i < this->currentSize; ++i)
    {
        if (this->games[i].isFree())
        {
            freeGames[writeIdx] = this->games[i];
        }
    }

    return freeGames;
}

void GamePlatform::saveToFile() const
{
    std::ofstream file(FILE_NAME);

    if (!file.is_open())
    {
        return;
    }

    file << PLATFORM_NAME << std::endl;

    for (int i = 0; i < this->currentSize; ++i)
    {
        file << this->games[i].getTitle()
             << "|" << this->games[i].getPrice()
             << "|" << this->games[i].getIsAvailable()
             << std::endl;
    }

    file.close();
}

Game parseLine(char *line)
{
    if (!line)
    {
        return Game({"Unknown", -1, false});
    }

    char name[LINE_SIZE] = {'\0'};
    int idx = 0;
    int price = 0;

    while (*line && line[idx] != '|')
    {
        name[idx] = line[idx];
        ++idx;
    }
    ++idx;

    while (*line && line[idx] != '|')
    {
        price = price * 10 + line[idx] - '0';
        ++idx;
    }

    return Game(name, price, line[idx + 2]);
}

void GamePlatform::loadFromFile()
{
    std::ifstream file(FILE_NAME);

    if (!file.is_open())
    {
        return;
    }

    {
        char line[LINE_SIZE] = {'\0'};

        file.getline(line, LINE_SIZE);

        if (!myStrCmp(line, PLATFORM_NAME))
        {
            return;
        }
    }

    while (true)
    {
        char line[LINE_SIZE] = {'\0'};

        file.getline(line, LINE_SIZE);

        if (file.eof())
        {
            return;
        }

        this->add(parseLine(line));
    }
}
