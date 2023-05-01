#include "MagicCard.h"

MagicCard::MagicCard()
{
	name[0] = '\0';
	effect[0] = '\0';
	type = CardType::unknown;
}

MagicCard::MagicCard(const char* name, const char* effect, const CardType type)
{
	strcpy(this->name, name);
	strcpy(this->effect, effect);
	this->type = type;
}

MagicCard::MagicCard(const MagicCard& other) = default;

MagicCard& MagicCard::operator=(const MagicCard& other) = default;

MagicCard::~MagicCard() = default;

const char* MagicCard::getName() const
{
	return name;
}

const char* MagicCard::getEffect() const
{
	return effect;
}

CardType MagicCard::getType() const
{
	return type;
}