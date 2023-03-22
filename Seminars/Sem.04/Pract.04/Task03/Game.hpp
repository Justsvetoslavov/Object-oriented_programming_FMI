#include <cstring>

const size_t MAX_TITLE_LENGTH = 64;


class Game {
private:
    char title[MAX_TITLE_LENGTH + 1];
    float price;
    bool isAvailable;

public:
    Game();

    Game(const char *title, float price, bool isAvailable);

    const char *getTitle() const;

    void setTitle(const char *title);

    float getPrice() const;

    void setPrice(float price);

    bool getIsAvailable() const;

    void setIsAvailable(bool isAvailable);

    bool isFree() const;

    void print() const;
};