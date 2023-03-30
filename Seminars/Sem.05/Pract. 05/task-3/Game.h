#pragma once

class Game {
private:
    char *title;
    double price;
    bool isAvailable;

    void free();

    void copyFrom(const Game &other);

    void copyTitle(const char* title);

public:
    Game() = default;

    Game(Game &other);

    Game &operator=(const Game &other);

    ~Game();

    // getters
    const char *getTitle() const;

    double getPrice() const;

    bool getIsAvailable() const;

    // setters
    void setTitle(const char* title);

    void setPrice(double price);

    void setIsAvailable(bool isAvailable);

    bool isFree() const;

    void print() const;
};