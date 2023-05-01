#include "Deck.h"
#include "MagicCard.h"
#include "MonsterCard.h"

Deck::Deck() = default;

Deck::Deck(const Deck& other) = default;

Deck& Deck::operator=(const Deck& other) = default;

Deck::~Deck() = default;

const size_t Deck::monsterCardsNumber() const
{
	return numberOfMonsterCards;
}

const size_t Deck::magicCardsNumber() const
{
	return numberOfMagicCards;
}

void Deck::addMonsterCard(const MonsterCard& monsterCard)
{
	for (size_t i = 0; i < CARDS_NUMBER; ++i)
	{
		if (i == numberOfMonsterCards - 1)
		{
			monsterCards[i] = monsterCard;
			++numberOfMonsterCards;
		}
	}
}

void Deck::addMagicCard(const MagicCard& magicCard)
{
	for (size_t i = 0; i < CARDS_NUMBER; ++i)
	{
		if (i == numberOfMagicCards - 1)
		{
			magicCards[i] = magicCard;
			++numberOfMagicCards;
		}
	}
}

void Deck::changeMonsterCardAtIndex(const MonsterCard& monsterCard, const size_t index)
{
	for (size_t i = 0; i < numberOfMonsterCards; ++i)
	{
		if (i == index)
		{
			monsterCards[i] = monsterCard;
		}
	}
}

void Deck::changeMagicCardAtIndex(const MagicCard& magicCard, const size_t index)
{
	for (size_t i = 0; i < numberOfMagicCards; ++i)
	{
		if (i == index)
		{
			magicCards[i] = magicCard;
		}
	}
}

void Deck::removeMonsterCardAtIndex(const size_t index)
{
	for (size_t i = 0; i < numberOfMonsterCards; ++i)
	{
		if (i == index)
		{
			for (size_t j = i; j < numberOfMonsterCards - i; ++j)
			{
				monsterCards[j] = monsterCards[j + 1];
				--numberOfMonsterCards;
			}

			i = numberOfMonsterCards;
		}
	}
}

void Deck::removeMagicCardAtIndex(const size_t index)
{
	for (size_t i = 0; i < numberOfMagicCards; ++i)
	{
		if (i == index)
		{
			for (size_t j = i; j < numberOfMagicCards - i; ++j)
			{
				magicCards[j] = magicCards[j + 1];
				--numberOfMagicCards;
			}

			i = numberOfMagicCards;
		}
	}
}
