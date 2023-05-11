#include "Duelist.h"
#include <cstring>
#pragma warning (disable : 4996)
void Duelist::CopyName(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Duelist::CopyFrom(const Duelist& duelist) {
	CopyName(duelist.name);
	this->deck = duelist.deck;
}
void Duelist::Free() {
	delete[] this->name;
	this->name = nullptr;
}

Duelist::Duelist(const char* name) {
	SetName(name);
}
Duelist::Duelist(const Duelist& other) {
	CopyFrom(other);
}
Duelist& Duelist::operator=(const Duelist& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}

	return (*this);
}
Duelist::~Duelist() {
	Free();
}

void Duelist::SetName(const char* name) {
	if (!name)
		return;

	if (this->name)
		delete[] name;

	CopyName(name);
}

void Duelist::SetDeck(const Deck& deck) {
	this->deck = deck;
}

size_t Duelist::GetMonsterCardsCountInDeck() const {
	return this->deck.GetMonsterCardsCount();
}
size_t Duelist::GetMagicCardsCountInDeck() const {
	return this->deck.GetMagicCardsCount();
}
bool Duelist::AddMonsterCardInDeck(const MonsterCard& mc) {
	return this->deck.AddMonsterCard(mc);
}
bool Duelist::AddMagicCardInDeck(const MagicCard& mc) {
	return this->deck.AddMagicCard(mc);
}
bool Duelist::ChangeMonsterInDeck(size_t id, const MonsterCard& mc) {
	return this->deck.ChangeMonsterCard(id, mc.GetName(), mc.GetAttackPoints(), mc.GetDefensePoints());
}
bool Duelist::ChangeMagicInDeck(size_t id, const MagicCard& mc) {
	return this->deck.ChangeMagicCard(id, mc.GetName(), mc.GetEffect(), mc.GetType());
}
bool Duelist::RemoveMonsterInDeck(size_t id) {
	return this->deck.RemoveMonsterCard(id);
}
bool Duelist::RemoveMagicInDeck(size_t id) {
	return this->deck.RemoveMagicCard(id);
}