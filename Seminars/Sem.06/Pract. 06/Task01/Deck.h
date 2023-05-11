#pragma once
#include "MagicCard.h"
#include "MonsterCard.h"

const int MAX_CARDS = 20;

class Deck
{
private:
	MonsterCard monsterCards[MAX_CARDS];
	MagicCard magicCards[MAX_CARDS];
	size_t monsterCardsCount = 0;
	size_t magicCardsCount = 0;
public:
	Deck() = default;
	size_t GetMonsterCardsCount() const;
	size_t GetMagicCardsCount() const;
	bool AddMonsterCard(const MonsterCard& mc);
	bool AddMagicCard(const MagicCard& mc);
	bool ChangeMonsterCard(size_t id, const char* name, size_t attackPoints, size_t defencePoints);
	bool ChangeMagicCard(size_t id, const char* name, const char* effect, const Type& type);
	bool RemoveMonsterCard(size_t id);
	bool RemoveMagicCard(size_t id);

};
