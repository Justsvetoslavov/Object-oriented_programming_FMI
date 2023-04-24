#include "../Deck/Deck.h"

class Duelist {
    char* name;
    Deck deck;

    void free();
    void copyFrom(const Duelist& duelist);

public:

    Duelist(const Duelist& duelist);

    Duelist();

    Duelist(const char* name, Deck deck1);

    ~Duelist();

    Duelist& operator=(const Duelist& duelist);
};
