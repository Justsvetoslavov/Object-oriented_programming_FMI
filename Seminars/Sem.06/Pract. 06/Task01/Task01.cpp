#include <iostream>
#include "Duelist.h"

int main()
{
	Deck d;

	d.ChangeMonsterCard(4, "Blue-eyes white dragon", 3000, 2500);
	d.ChangeMagicCard(5, "Monster reborn", "revive", Type::spell);

	std::cout << d.GetMagicCardsCount();
	std::cout << d.GetMonsterCardsCount();

	Duelist player1("Seto Kaiba");
	
	MonsterCard darkMagician("Dark Magician", 2500, 2100);
	player1.ChangeMonsterInDeck(2, darkMagician);

	Duelist player2("Yugi Muto");

	MagicCard reflection("Reflection", "Reflects the last played spell", Type::trap);
	player2.ChangeMagicInDeck(2, reflection);
	player2.RemoveMagicInDeck(2);
	std::cout << player2.GetMagicCardsCountInDeck();
}
