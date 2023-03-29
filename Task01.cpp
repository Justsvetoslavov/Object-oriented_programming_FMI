#include "Duelist/Duelist.h"
#include <iostream>

int main() {
    Deck d;
    d.addMonster(Monster("Test1", 1, 1));
    d.addMonster(Monster("Test1", 1, 1));
    d.addMonster(Monster("Test1", 1, 1));
    d.addMonster(Monster("Test1", 1, 1));
    d.addMagic(Magic("Test1", "none", Type::buff));
    d.addMagic(Magic("Test1", "none", Type::buff));
    d.addMagic(Magic("Test1", "none", Type::buff));
    d.addMagic(Magic("Test1", "none", Type::buff));
    d.editMonster(Monster("Blue-eyes white dragon", 3000, 2500), 0);
    d.editMagic(Magic("Monster reborn", "revive", Type::spell), 0);
    d.delMagic(3);
    d.delMonster(3);
    Deck f = d;
    std::cout << ")";
}