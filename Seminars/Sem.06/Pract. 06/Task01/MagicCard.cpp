#include "MagicCard.h"
#include <cstring>
#pragma warning(disable: 4996)

MagicCard::MagicCard() : MagicCard("Unknown", "Unknown", trap){}

MagicCard::MagicCard(const char* name, const char* effect, type cardType) {
	if (name == nullptr || effect == nullptr)
		return;
	strcpy(this->name, name);
	strcpy(this->effect, effect);
	this->cardType = cardType;
}