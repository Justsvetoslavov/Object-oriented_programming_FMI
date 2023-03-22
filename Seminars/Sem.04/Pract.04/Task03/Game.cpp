#include <iostream>
#include "Game.hpp"

using std::cout, std::endl, std::boolalpha;


Game::Game() {
    title[0] = '\0';
    price = 0;
    isAvailable = false;
}

Game::Game(const char *title, float price, bool isAvailable) {
    setTitle(title);
    setPrice(price);
    setIsAvailable(isAvailable);
}

const char *Game::getTitle() const {
    return title;
}

void Game::setTitle(const char *title) {
    if (strlen(title) > MAX_TITLE_LENGTH) {
        std::cout << "Title is too long!" << std::endl;
        return;
    }
    strcpy(this->title, title);
}

float Game::getPrice() const {
    return price;
}

void Game::setPrice(float price) {
    if (price < 0) {
        std::cout << "Price cannot be negative!" << std::endl;
        return;
    }
    this->price = price;
}

bool Game::getIsAvailable() const {
    return isAvailable;
}

void Game::setIsAvailable(bool isAvailable) {
    this->isAvailable = isAvailable;
}

bool Game::isFree() const {
    if (this->price == 0) {
        return true;
    }
}

void Game::print() const {
    cout << "Title: " << title << endl;
    cout << "Price: " << price << endl;
    cout << "Is available: " << boolalpha << isAvailable << endl << endl;
}
