#include "MagicCard.h"
#include <cstring>
#pragma warning(disable : 4996)

MagicCard::MagicCard() {
	name[0] = '\0';
	effect[0] = '\0';
	type = MagicCardType::unknown;
}

MagicCard::MagicCard(const char* name, const char* effect, const MagicCardType type){
	strcpy(this->name, name);
	strcpy(this->effect, effect);
	this->type = type;
}

const char* const MagicCard::getName() const {
	return name;
}
const char* const MagicCard::getEffect() const {
	return effect;
}
MagicCardType MagicCard::getMagicCardType() const{
	return type;
}