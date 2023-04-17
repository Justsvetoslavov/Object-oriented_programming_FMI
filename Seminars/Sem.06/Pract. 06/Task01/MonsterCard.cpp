#include "MonsterCard.h"
#include <cstring>
#pragma warning(disable : 4996)

MonsterCard::MonsterCard() {
	name[0] = '\0';
	attPoints = 0;
	defPoints = 0;
}

MonsterCard::MonsterCard(const char* name, size_t attPoints, size_t defPoints) {
	strcpy(this->name, name);
	this->attPoints = attPoints;
	this->defPoints = defPoints;
}

const char* const MonsterCard::getName() const {
	return name;
}

size_t MonsterCard::getAttPoints() const{
	return attPoints;
}

size_t MonsterCard::getDefPoints() const{
	return defPoints;
}
