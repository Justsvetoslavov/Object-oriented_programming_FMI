#include<cstring>
#include "Deck.h"

Deck::Deck() : magicCardsSize(0), monsterCardsSize(0) {
	for (size_t i = 0; i <  MAX_DECK_SIZE / 2; i++)
	{
		monsterCardUsedPositions[i] = magicCardUsedPositions[i] = false;
	}
}

size_t Deck::getMagicCardsSize() const{
	return magicCardsSize;
}

size_t Deck::getMonsterCardsSize() const{
	return monsterCardsSize;
}

bool Deck::addMagicCardToDeck(const MagicCard& magicCard) {
	for (size_t i = 0; i < MAX_DECK_SIZE / 2; i++)
	{
		if (!magicCardUsedPositions[i])
		{
			magicCards[i] = magicCard;
			magicCardUsedPositions[i] = true;
			magicCardsSize++;
			return true;
		}
	}
	return false;
}

bool Deck::addMonsterCardToDeck(const MonsterCard& monsterCard) {
	for (size_t i = 0; i < MAX_DECK_SIZE / 2; i++)
	{
		if (!monsterCardUsedPositions[i])
		{
			monsterCards[i] = monsterCard;
			monsterCardUsedPositions[i] = true;
			monsterCardsSize++;
			return true;
		}
	}
	return false;
}

bool Deck::addMagicCardToDeckAtIndex(const MagicCard& magicCard, const int index) {
	if (index >=  MAX_DECK_SIZE / 2)
		return false;

	if (!magicCardUsedPositions[index])
		magicCardsSize++;

	magicCards[index] = magicCard;
	magicCardUsedPositions[index] = true;

	return true;
}

bool Deck::addMonsterCardToDeckAtIndex(const MonsterCard& monsterCard, const int index) {
	if (index >= MAX_DECK_SIZE / 2)
		return false;

	if (!monsterCardUsedPositions[index])
		monsterCardsSize++;

	monsterCards[index] = monsterCard;
	monsterCardUsedPositions[index] = true;

	return true;
}

void Deck::info() const
{
	std::cout << "Monster Cards: " << monsterCardsSize << std::endl;
	std::cout << "Magic Cards: " << magicCardsSize << std::endl;
	std::cout << "Deck size: " << monsterCardsSize + magicCardsSize << std::endl;
}
