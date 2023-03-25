#include "Game.h"

Game::Game() {
    title = nullptr;
    price = -1;
    isAvailable = false;
}

Game::Game(const char *title, float price, bool isAvailable) {
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
    this->price = price;
    this->isAvailable = isAvailable;
}

const char *Game::getTitle() const {
    return title;
}

float Game::getPrice() const {
    return price;
}

bool Game::getIsAvailable() const {
    return isAvailable;
}

void Game::SetTitle(const char *title) {
    if (this->title != nullptr)
        delete[]this->title;
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
}

void Game::SetPrice(float price) {
    this->price = price;
}

void Game::SetIsAvailable(bool isAvailable) {
    this->isAvailable = isAvailable;
}

bool Game::isFree() const {
    if (1 - price < 1)
        return false;
    return true;
}

void Game::print() const {
    std::cout << "Title: " << title << std::endl
              << "Price: " << price << std::endl
              << "Available: " << (isAvailable ? "Yes" : "No") << std::endl;
}