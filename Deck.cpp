#include "Deck.h"

void Deck::addMagic(const Magic &card) {
    magic[amountMagic++] = card;
}

void Deck::addMonster(const Monster& card) {
    monsters[amountMonsters++] = card;
}

void Deck::editMagic(const Magic &card, const int pos) {
    magic[pos] = card;
}

void Deck::editMonster(const Monster &card, const int pos) {
    monsters[pos] = card;
}

void Deck::delMagic(const int pos) {
    for (int i = pos; i < amountMagic - 1; ++i)
        magic[i] = magic[i + 1];
    magic[--amountMagic].delMagic();
}

void Deck::delMonster(const int pos) {
    for (int i = pos; i < amountMonsters - 1; ++i)
        monsters[i] = monsters[i + 1];
    monsters[--amountMonsters].delMonster();
}

Deck &Deck::operator=(Deck deck1) {
    for (int i = 0; i < deck1.amountMonsters; ++i)
        this->monsters[i] = monsters[i];
    if (deck1.amountMonsters < this->amountMonsters)
        for (int i = this->amountMonsters; i < this->amountMonsters - deck1.amountMonsters; ++i)
            this->monsters[i].delMonster();
    for (int i = 0; i < deck1.amountMagic; ++i)
        this->magic[i] = magic[i];
    if (deck1.amountMagic < this->amountMagic)
        for (int i = this->amountMagic; i < this->amountMagic - deck1.amountMagic; ++i)
            this->magic[i].delMagic();
    return *this;
}