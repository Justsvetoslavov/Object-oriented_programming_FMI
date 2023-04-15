#include "Duelist.h"
#include <cstring>
#pragma warning(disable: 4996)

Duelist::Duelist(const char* name, const Deck& deck) {
	SetName(name);
	this->deck = deck;
}

Duelist::Duelist(const Duelist& other) {
	copyFrom(other);
}

Duelist& Duelist::operator=(const Duelist& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Duelist::~Duelist() {
	free();
}

void Duelist::SetName(const char* name) {
	if (name == nullptr)
		return;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Duelist::AddMagicCardInDeck(const char* name, const char* effect, type cardType) {
	deck.AddMagicCard(name, effect, cardType);
}

void Duelist::AddMagicCardInDeck(const MagicCard& card) {
	deck.AddMagicCard(card);
}

void Duelist::AddMonsterCardInDeck(const char* name, int attackPoints, int defensePoints) {
	deck.AddMonsterCard(name, attackPoints, defensePoints);
}

void Duelist::AddMonsterCardInDeck(const MonsterCard& card) {
	deck.AddMonsterCard(card);
}

void Duelist::ChangeMagicCardInDeck(int index, const char* name, const char* effect, type cardType) {
	deck.ChangeMagicCard(index, name, effect, cardType);
}

void Duelist::ChangeMagicCardInDeck(int index, const MagicCard& card){
	deck.ChangeMagicCard(index, card);
}

void Duelist::ChangeMonsterCardInDeck(int index, const char* name, int attackPoints, int defensePoints) {
	deck.ChangeMonsterCard(index, name, attackPoints, defensePoints);
}

void Duelist::ChangeMonsterCardInDeck(int index, const MonsterCard& card){
	deck.ChangeMonsterCard(index, card);
}

void Duelist::RemoveMagicCardFromDeck(int index){
	deck.RemoveMagicCard(index);
}

void Duelist::RemoveMonsterCardFromDeck(int index){
	deck.RemoveMonsterCard(index);
}

void Duelist::copyFrom(const Duelist& other) {
	SetName(other.name);
	this->deck = other.deck;
}

void Duelist::free() {
	delete[] name;
	name = nullptr;
}
