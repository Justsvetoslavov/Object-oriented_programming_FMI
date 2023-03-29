#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>


class Game {
    char *title;
    double price;
    bool isAvailable;
public:

    Game();
    Game(const char* title,const float &price,const bool &isAvailable);

    const char* getTitle() const;
    float getPrice() const;
    bool getIsAvailable() const;

    Game setTitle(const char* title);
    Game setPrice(const float &price);
    Game setIsAvailable(const bool &isAvailable);

    void print();
    std::string buildString();
    bool isFree();
    bool isEqual(Game game);

    Game& operator = (const Game game);

    virtual ~Game();

};