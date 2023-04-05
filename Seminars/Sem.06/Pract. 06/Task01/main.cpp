#include <iostream>

#include "Duelist.h"

int main(){
    Deck d1;

    d1.addMagicCard("Monster reborn", "revive", Type::spell);
    d1.addMagicCard("Pot of Greed", "revive", Type::spell);
    d1.addMagicCard("Lightning Storm", "revive", Type::buff);

    d1.addMonsterCard("Blue-eyes white dragon", 3000, 2500);

    Deck d2;

    d2.addMagicCard("Vanity's emptiness", "Neither player can Special Summon monsters", Type::trap);
    d2.addMagicCard("Magic Cylinder", "When an opponent's monster declares an attack: Target the attacking monster;", Type::trap);
    d2.addMagicCard("Anti-Spell Fragrance", "Both players must Set Spell Cards before activating them.", Type::trap);

    d2.addMonsterCard("Accesscode Talker", 2300, 0);
    d2.addMonsterCard("Borreload Savage Dragon", 3000, 2500);
    d2.addMonsterCard("Destiny HERO3 - Destroyer Phoenix Enforcer", 2500, 2100);

    Duelist player1("Seto Kaiba");
    d1 = d2;
    player1.setDeck(&d1);
    player1.print();
    std::cout << std::endl;

    Monster DarkMagician("Dark Magician", 2500, 2100);
    player1.changeMonsterInDeck(1, DarkMagician);
    player1.print();
    std::cout << std::endl;

    d1.changeMagicCard(0, "Monster reborn", "revive", Type::spell);
    d1.changeMagicCard(1, "Pot of Greed", "revive", Type::spell);
    d1.addMagicCard("Reflection", "Reflects the last played spell", Type::trap);
    d1.deleteMonsterCard(0);
    d1.deleteMonsterCard(0);
    player1.print();

   std::cout << d1.getNumberOfMagicCards() << " " << d1.getNumberOfMonsterCards();
}
