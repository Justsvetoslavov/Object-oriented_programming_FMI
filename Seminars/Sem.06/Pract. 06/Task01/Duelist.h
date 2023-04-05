#pragma once

#include "Deck.h"

class Duelist {
	char* name = nullptr;

	// A deck can exists independently (and be changed independently).
	// For this reason, I chose agregation.
	Deck* deck = nullptr;

	void copyFrom(const Duelist& other);
	void free();
	void copyName(const char* newName);

public:
	Duelist() = default;
	Duelist(const char* name, Deck* deck);
	Duelist(const char* name);
	Duelist(const Duelist& other);

	Duelist& operator=(const Duelist& other);

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

	void setName(const char* name);
	void setDeck(Deck* deck);

	void deleteMonsterCard(size_t ind);
	void deleteMagicCard(size_t ind);

	void print() const;

	~Duelist();
};