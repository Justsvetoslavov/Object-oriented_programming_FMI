#include "Duelist.h"

Duelist::Duelist(const char *name, Deck deck1) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    deck = deck1;
}

Duelist::Duelist(const Duelist &duelist) {
    copyFrom(duelist);
}

Duelist::~Duelist() {
    delete[] name;
}

Duelist::Duelist()  {
    name = new char[1];
    name[0] = '\0';
}

Duelist &Duelist::operator=(const Duelist &duelist) {
    if (this != &duelist) {
        free();
        copyFrom(duelist);
    }
    return *this;
}

void Duelist::copyFrom(const Duelist &duelist) {
    name = new char[strlen(duelist.name) + 1];
    strcpy(name, duelist.name);
    deck = duelist.deck;
}

void Duelist::free() {
    delete[] name;
}