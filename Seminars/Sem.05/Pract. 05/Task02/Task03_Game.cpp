#include <iostream>
#include "Task03_Game.h"
#include "Task03_Utils.h"

const int DEFAULT_TITLE_SIZE = 16;
const double EPSILON = 0.0001;

Game::Game()
{
    this->titleCapacity = DEFAULT_TITLE_SIZE;
    this->currentTitleSize = 0;

    this->title = new char[DEFAULT_TITLE_SIZE];

    this->price = -1;
    this->isAvailable = false;
};

Game::Game(const char *title, const double price, const bool isAvailable)
{
    this->titleCapacity = DEFAULT_TITLE_SIZE;
    this->currentTitleSize = 0;

    this->title = new char[DEFAULT_TITLE_SIZE];

    setTitle(title);
    setPrice(price);
    setIsAvailable(isAvailable);
}

Game &Game::operator=(const Game &game)
{
    this->setTitle(game.title);
    this->setPrice(game.price);
    this->setIsAvailable(game.isAvailable);

    return *this;
}

Game::Game(const Game &other)
{
    this->setTitle(other.title);
    this->setPrice(other.price);
    this->setIsAvailable(other.isAvailable);
}

void Game::setTitle(const char *title)
{
    if (!this->title)
    {
        myStrCpy(this->title, "Unknown");
        return;
    }

    int size = myStrLen(title);

    if (size > this->titleCapacity)
    {
        while (size > this->titleCapacity)
        {
            this->titleCapacity *= 2;
        }

        resize(this->title, titleCapacity);
    }

    myStrCpy(this->title, title);

    this->currentTitleSize = size + 1; // add 1 for terminating zero
}

void Game::setPrice(const double price)
{
    if (price < 0)
    {
        return;
    }

    this->price = price;
}

void Game::setIsAvailable(const bool isAvailable)
{
    this->isAvailable = isAvailable;
}

const char *Game::getTitle() const
{
    return this->title;
}

double Game::getPrice() const
{
    return this->price;
}

bool Game::getIsAvailable() const
{
    return this->isAvailable;
}

bool Game::isFree() const
{
    return (this->price < EPSILON);
}

void Game::print() const
{
    if (!this->title)
    {
        return;
    }
    const char *s = this->title;

    std::cout << "Game title: ";
    while (*s)
    {
        std::cout << *s++;
    }
    std::cout << std::endl;

    std::cout << "Price: " << this->price << std::endl;
    std::cout << "Is available: " << (this->isAvailable ? "true" : "false") << std::endl;

    std::cout << std::endl;
}

Game::~Game()
{
    delete[] this->title;
}
