#pragma once
#include "MonsterCard.h"
#include "MagicCard.h"

class Deck{
private:
	MonsterCard monsterCards[20];
	MagicCard magicCards[20];
	unsigned monsterCardsCount = 0;
	unsigned magicCardsCount = 0;

public:
	int GetMagicCardsCount() const;
	int GetMonstersCount() const;
	void AddMagicCard(const char* name, const char* effect, type cardType);
	void AddMagicCard(const MagicCard& card);
	void AddMonsterCard(const char* name, int attackPoints, int defensePoints);
	void AddMonsterCard(const MonsterCard& card);
	void ChangeMagicCard(int index, const char* name, const char* effect, type cardType);
	void ChangeMagicCard(int index, const MagicCard& card);
	void ChangeMonsterCard(int index, const char* name, int attackPoints, int defensePoints);
	void ChangeMonsterCard(int index, const MonsterCard& card);
	void RemoveMagicCard(int index);
	void RemoveMonsterCard(int index);
};

