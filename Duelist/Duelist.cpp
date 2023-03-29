#include "Duelist.h"

Duelist::Duelist(const char *name, Deck deck1) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    deck = deck1;
}