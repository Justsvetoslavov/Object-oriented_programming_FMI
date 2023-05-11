#include "MagicCard.h"
#include <cstring>
#pragma warning (disable : 4996)
MagicCard::MagicCard(const char* name, const char* effect, const Type type) {
	SetName(name);
	SetEffect(effect);
	SetType(type);
}

const char* MagicCard::GetName() const {
	return this->name;
}
const char* MagicCard::GetEffect() const {
	return this->effect;
}
const Type& MagicCard::GetType() const {
	return this->type;
}

void MagicCard::SetName(const char* name) {
	if (!name)
		return;

	strcpy(this->name, name);
}
void MagicCard::SetEffect(const char* effect) {
	if (!effect)
		return;

	strcpy(this->effect, effect);
}
void MagicCard::SetType(const Type type) {
	this->type = type;
}
