#pragma once
#include "Deck.h"

class Duelist
{
	char* name;
	Deck deck;

	void copyFrom(const Duelist& other);

	void free();

public:

	Duelist();

	Duelist(const Duelist& other);

	Duelist& operator=(const Duelist& other);

	~Duelist();

	const char* getName() const;

	Deck getDeck() const;

	void setName(const char* name);

	void setDeck(const Deck& deck);

	void addMonsterCard(const MonsterCard& monsterCard);

	void addMagicCard(const MagicCard& magicCard);

	void changeMonsterCardAtIndex(const MonsterCard& monsterCard, size_t index);

	void changeMagicCardAtIndex(const MagicCard& magicCard, size_t index);

	void removeMonsterCardAtIndex(const size_t index);

	void removeMagicCardAtIndex(const size_t index);
};

