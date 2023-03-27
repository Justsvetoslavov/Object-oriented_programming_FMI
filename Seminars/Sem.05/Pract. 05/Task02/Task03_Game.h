#pragma once

class Game
{
    char *title;
    double price;
    bool isAvailable;

    int currentTitleSize;
    int titleCapacity;

    void setTitle(const char *);
    void setPrice(const double);
    void setIsAvailable(const bool);

public:
    Game();
    Game(const char *, const double, const bool);

    Game &operator=(const Game &);
    Game(const Game &);

    const char *getTitle() const;
    double getPrice() const;
    bool getIsAvailable() const;

    bool isFree() const;
    void print() const;

    ~Game();
};
