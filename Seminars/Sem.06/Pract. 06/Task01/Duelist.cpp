#include "Duelist.h"
#pragma warning (disable: 4996)

void Duelist::copyFrom(const Duelist& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	deck = other.deck;
}

void Duelist::free()
{
	delete[] name;
}

Duelist::Duelist()
{
	name = new char[1];
	name[0] = '\0';
}

Duelist::Duelist(const Duelist& other)
{
	copyFrom(other);
}

Duelist& Duelist::operator=(const Duelist& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Duelist::~Duelist()
{
	free();
}

const char* Duelist::getName() const
{
	return name;
}

Deck Duelist::getDeck() const
{
	return deck;
}

void Duelist::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Duelist::setDeck(const Deck& deck)
{
	this->deck = deck;
}

void Duelist::addMonsterCard(const MonsterCard& monsterCard)
{
	return deck.addMonsterCard(monsterCard);
}

void Duelist::addMagicCard(const MagicCard& magicCard)
{
	return deck.addMagicCard(magicCard);
}

void Duelist::changeMonsterCardAtIndex(const MonsterCard& monsterCard, size_t index)
{
	return deck.changeMonsterCardAtIndex(monsterCard, index);
}

void Duelist::changeMagicCardAtIndex(const MagicCard& magicCard, size_t index)
{
	return deck.changeMagicCardAtIndex(magicCard, index);
}

void Duelist::removeMonsterCardAtIndex(const size_t index)
{
	return deck.removeMonsterCardAtIndex(index);
}

void Duelist::removeMagicCardAtIndex(const size_t index)
{
	return deck.removeMagicCardAtIndex(index);
}