#include "Deck.h"

size_t Deck::GetMonsterCardsCount() const {
	return this->monsterCardsCount;
}

size_t Deck::GetMagicCardsCount() const {
	return this->magicCardsCount;
}

bool Deck::AddMonsterCard(const MonsterCard& mc) {
	if (this->monsterCardsCount >= MAX_CARDS)
		return false;

	this->monsterCards[monsterCardsCount++] = mc;
	return false;
}
bool Deck::AddMagicCard(const MagicCard& mc) {
	if (this->magicCardsCount >= MAX_CARDS)
		return false;

	this->magicCards[magicCardsCount++] = mc;
	return false;
}

bool Deck::ChangeMonsterCard(size_t id, const char* name, size_t attackPoints, size_t defencePoints) {
	if (id < 0 || id > MAX_CARDS)
		return false;

	this->monsterCards[id] = MonsterCard(name, attackPoints, defencePoints);
	monsterCardsCount++;
	return true;
}
bool Deck::ChangeMagicCard(size_t id, const char* name, const char* effect, const Type& type) {
	if (id < 0 || id > MAX_CARDS)
		return false;

	this->magicCards[id] = MagicCard(name, effect, type);
	magicCardsCount++;
	return true;
}
bool Deck::RemoveMonsterCard(size_t id) {
	if (id < 0 || id > MAX_CARDS)
		return false;

	this->monsterCards[id].SetName("\0");
	this->monsterCards[id].SetAttackPoints(0);
	this->monsterCards[id].SetDefensePoints(0);
	monsterCardsCount--;
	return true;
}
bool Deck::RemoveMagicCard(size_t id) {
	if (id < 0 || id > MAX_CARDS)
		return false;

	if (id < 0 || id > MAX_CARDS)
		return false;

	this->magicCards[id].SetName("\0");
	this->magicCards[id].SetEffect("\0");

	magicCardsCount--;
	return true;
}