#include "../Deck/Deck.h"

class Duelist {
    char* name;
    Deck deck;

public:

    Duelist() {
        name = new char[1];
        name[0] = '\0';
    }

    Duelist(const char* name, Deck deck1);

    ~Duelist() {
        delete[] name;
    }
};
