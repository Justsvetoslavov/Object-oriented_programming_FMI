#pragma once
#include "../Monster/Monster.h"
#include "../Magic/Magic.h"

const int MAX_CARDS = 20;

class Deck {
    Monster monsters[MAX_CARDS];
    Magic magic[MAX_CARDS];
    int amountMonsters = 0, amountMagic = 0;

public:

    Deck() = default;

    void addMagic(const Magic& card);

    void addMonster(const Monster& card);

    void editMagic(const Magic& card, const int pos);

    void editMonster(const Monster &card, const int pos);

    void delMagic(const int pos);

    void delMonster(const int pos);

    Deck& operator=(Deck deck1);
};
