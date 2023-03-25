#pragma once

#include <iostream>
#include <cstring>

class Game {
    char *title;
    float price;
    bool isAvailable;
public:
    Game();

    Game(const char *title, float price, bool isAvailable);

    const char *getTitle() const;

    float getPrice() const;

    bool getIsAvailable() const;

    void SetTitle(const char *title);

    void SetPrice(float price);

    void SetIsAvailable(bool isAvailable);

    bool isFree() const;

    void print() const;
};
