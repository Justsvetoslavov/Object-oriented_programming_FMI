#include "Game.h"
#include <iostream>
#include <cstring>


void Game::free() {
    delete[] this->title;
    this->title = nullptr;
}

void Game::copyFrom(const Game &other) {
    this->setTitle(other.getTitle());
    this->setPrice(other.getPrice());
    this->setIsAvailable(other.getIsAvailable());
}

void Game::copyTitle(const char *title) {
    if (title == nullptr) {
        return;
    }
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
}


Game &Game::operator=(const Game &other) {
    if(this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Game::Game(Game &other) {
    this->free();
    this->copyFrom(other);
}

Game::~Game() {
    this->free();
}

// getters
const char *Game::getTitle() const {
    return title;
}

double Game::getPrice() const {
    return price;
}

bool Game::getIsAvailable() const {
    return isAvailable;
}

// setters
void Game::setTitle(const char *title) {
    if (title == nullptr) {
        return;
    }

    delete[] this->title;
    copyTitle(title);
}

void Game::setPrice(double price) {
    if (price < 0) {
        price = 0;
    }
    this->price = price;
}

void Game::setIsAvailable(bool isAvailable) {
    this->isAvailable = isAvailable;
}

bool Game::isFree() const {
    return price < 0.01;
}

void Game::print() const {
    std::cout << "Title: " << this->getTitle() << std::endl;
    std::cout << "Price: " << this->getPrice() << std::endl;
    std::cout << "IsAvailable: " << this->getIsAvailable() << std::endl;
}

