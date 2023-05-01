#pragma once
#include "MonsterCard.h"
#include "MagicCard.h"

const int CARDS_NUMBER = 20;

class Deck
{
	MonsterCard monsterCards[CARDS_NUMBER];
	MagicCard magicCards[CARDS_NUMBER];

	size_t numberOfMonsterCards;
	size_t numberOfMagicCards;

public:

	Deck();

	Deck(const Deck& other);

	Deck& operator=(const Deck& other);

	~Deck();

	const size_t monsterCardsNumber() const;

	const size_t magicCardsNumber() const;

	void addMonsterCard(const MonsterCard& monsterCard);

	void addMagicCard(const MagicCard& magicCard);

	void changeMonsterCardAtIndex(const MonsterCard& monsterCard, const size_t index);

	void changeMagicCardAtIndex(const MagicCard& magicCard, const size_t index);

	void removeMonsterCardAtIndex(const size_t index);

	void removeMagicCardAtIndex(const size_t index);
};