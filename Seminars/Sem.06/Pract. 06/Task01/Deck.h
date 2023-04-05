#pragma once

#include "Monster.h"
#include "MagicCard.h"

const int MAX_NUMBER_OF_MONSTER_CARDS = 20;
const int MAX_NUMBER_OF_MAGIC_CARDS = 20;

class Deck {
	Monster monsterCards[MAX_NUMBER_OF_MONSTER_CARDS];
	MagicCard magicCards[MAX_NUMBER_OF_MAGIC_CARDS];

	size_t numberOfMonsterCards = 0;
	size_t numberOfMagicCards = 0;

public:
	void addMagicCard(const char* name, const char* effect, const Type& type);
	void addMonsterCard(const char* name, size_t attack, size_t defense);

	void addMagicCard(const MagicCard& magicCard);
	void addMonsterCard(const Monster& monster);

	size_t getNumberOfMonsterCards() const;
	size_t getNumberOfMagicCards() const;

	void changeMonsterCard(size_t ind, const char* name, size_t attack, size_t defense);
	void changeMagicCard(size_t ind, const char* name, const char* effect, const Type& type);

	void changeMonsterInDeck(size_t ind, const Monster& monster);
	void changeMagicCardInDeck(size_t ind, const MagicCard& magicCard);

	void deleteMonsterCard(size_t ind);
	void deleteMagicCard(size_t ind);

	void print() const;
};