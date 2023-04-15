#include <iostream>
#include "Duelist.h"

int main()
{
    Deck deck;
    deck.AddMagicCard("Magical card", "something", spell);
    deck.AddMagicCard("Name", "action", trap);
    deck.RemoveMagicCard(2);

    Duelist duelist("Nepal", deck);
    duelist.AddMagicCardInDeck("Magic", "does some magic", spell);
    MonsterCard card("Monster", 100, 200);
    duelist.AddMonsterCardInDeck(card);
    duelist.ChangeMonsterCardInDeck(1, "New monster", 400, 1500);
}

