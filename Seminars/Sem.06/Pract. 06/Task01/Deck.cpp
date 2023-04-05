#include "Deck.h"

#include <iostream>

void Deck::addMagicCard(const char* name, const char* effect, const Type& type) {
	if (numberOfMagicCards >= MAX_NUMBER_OF_MAGIC_CARDS) {
		return;
	}
	magicCards[numberOfMagicCards++] = MagicCard(name, effect, type);
}

void Deck::addMonsterCard(const char* name, size_t attack, size_t defense) {
	if (numberOfMonsterCards >= MAX_NUMBER_OF_MONSTER_CARDS) {
		return;
	}
	monsterCards[numberOfMonsterCards++] = Monster(name, attack, defense);
}

void Deck::addMagicCard(const MagicCard& magicCard) {
	if (numberOfMagicCards >= MAX_NUMBER_OF_MAGIC_CARDS) {
		return;
	}
	magicCards[numberOfMagicCards++] = magicCard;
}

void Deck::addMonsterCard(const Monster& monster) {
	if (numberOfMonsterCards >= MAX_NUMBER_OF_MONSTER_CARDS) {
		return;
	}
	monsterCards[numberOfMonsterCards++] = monster;
}

size_t Deck::getNumberOfMonsterCards() const {
	return numberOfMonsterCards;
}

size_t Deck::getNumberOfMagicCards() const {
	return numberOfMagicCards;
}

void Deck::changeMonsterCard(size_t ind, const char* name, size_t attack, size_t defense) {
	if (ind >= numberOfMonsterCards) {
		return;
	}
	monsterCards[ind] = Monster(name, attack, defense);
}

void Deck::changeMagicCard(size_t ind, const char* name, const char* effect, const Type& type) {
	if (ind >= numberOfMagicCards) {
		return;
	}
	magicCards[ind] = MagicCard(name, effect, type);
}

void Deck::changeMonsterInDeck(size_t ind, const Monster& monster) {
	if (ind >= numberOfMonsterCards) {
		return;
	}
	monsterCards[ind] = monster;
}

void Deck::changeMagicCardInDeck(size_t ind, const MagicCard& magicCard) {
	if (ind >= numberOfMagicCards) {
		return;
	}
	magicCards[ind] = magicCard;
}

void Deck::deleteMonsterCard(size_t ind){
	if (ind >= numberOfMonsterCards) {
		return;
	}

	monsterCards[ind] = monsterCards[numberOfMonsterCards - 1];
	numberOfMonsterCards--;
}

void Deck::deleteMagicCard(size_t ind) {
	if (ind >= numberOfMagicCards) {
		return;
	}

	magicCards[ind] = magicCards[numberOfMagicCards - 1];
	numberOfMagicCards--;
}

void Deck::print() const {
	std::cout << std::endl << "Monster cards:" << std::endl;
	for (int i = 0; i < numberOfMonsterCards; i++) {
		monsterCards[i].print();
	}

	std::cout << std::endl << "Magic cards:" << std::endl;
	for (int i = 0; i < numberOfMagicCards; i++) {
		magicCards[i].print();
	}
}