#pragma once
#include "Deck.h"

class Duelist
{
private:
	char* name;
	Deck deck;
public:
	Duelist(const char* name);
	Duelist(const Duelist& other);
	Duelist& operator=(const Duelist& other);
	~Duelist();

	void SetName(const char* name);

	void SetDeck(const Deck& deck);
	size_t GetMonsterCardsCountInDeck() const;
	size_t GetMagicCardsCountInDeck() const;
	bool AddMonsterCardInDeck(const MonsterCard& mc);
	bool AddMagicCardInDeck(const MagicCard& mc);
	bool ChangeMonsterInDeck(size_t id, const MonsterCard& mc);
	bool ChangeMagicInDeck(size_t id, const MagicCard& mc);
	bool RemoveMonsterInDeck(size_t id);
	bool RemoveMagicInDeck(size_t id);

private:
	void CopyName(const char* name);
	void CopyFrom(const Duelist& duelist);
	void Free();
};
