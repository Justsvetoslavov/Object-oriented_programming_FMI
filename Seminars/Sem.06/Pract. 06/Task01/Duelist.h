#pragma once
#include "Deck.h"

class Duelist {
private:
	char* name = nullptr;
	Deck deck;
public:
	Duelist(const char* name, const Deck& deck);
	Duelist(const Duelist& other);
	Duelist& operator=(const Duelist& other);
	~Duelist();

	void SetName(const char* name);

	void AddMagicCardInDeck(const char* name, const char* effect, type cardType);
	void AddMagicCardInDeck(const MagicCard& card);
	void AddMonsterCardInDeck(const char* name, int attackPoints, int defensePoints);
	void AddMonsterCardInDeck(const MonsterCard& card);
	void ChangeMagicCardInDeck(int index, const char* name, const char* effect, type cardType);
	void ChangeMagicCardInDeck(int index, const MagicCard& card);
	void ChangeMonsterCardInDeck(int index, const char* name, int attackPoints, int defensePoints);
	void ChangeMonsterCardInDeck(int index, const MonsterCard& card);
	void RemoveMagicCardFromDeck(int index);
	void RemoveMonsterCardFromDeck(int index);

private:
	void copyFrom(const Duelist& other);
	void free();
};

