#pragma once
#include "Deck.h"

class Duelist {
	char* name;
	Deck deck;
public:
	Duelist();
	Duelist(const char*, const Deck&);
	Duelist(const Duelist&);
	Duelist& operator=(const Duelist&);
	~Duelist();
	
	void setName(const char*);
	void setDeck(const Deck&);

	const char* getName() const;
	Deck getDeck() const;

	bool addMonsterCard(const MonsterCard& monsterCard);
	bool addMagicCard(const MagicCard& MagicCard);

	bool changeMonsterCardAtIndex(const MonsterCard& monsterCard, const int index);
	bool changeMagicCardAtIndex(const MagicCard& magicCard, const int index);
	
	void display() const;
private:
	void copy(const Duelist& duelist);
	void free();
};
