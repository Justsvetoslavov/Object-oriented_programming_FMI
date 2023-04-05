#include "Duelist.h"

#include <iostream>

namespace {
	size_t myStrlen(const char* str) {
		if (str == nullptr) {
			return 0;
		}

		size_t ctr = 0;
		while (*str) {
			str++;
			ctr++;
		}

		return ctr;
	}

	void myStrcpy(char* dest, const char* src) {
		if (src == nullptr || dest == nullptr) {
			return;
		}

		while (*src) {
			*(dest) = *(src);
			src++;
			dest++;
		}

		*(dest) = '\0';
	}
}

void Duelist::copyFrom(const Duelist& other) {
	copyName(other.name);
	this->deck = other.deck;
}

void Duelist::free() {
	delete[] name;
}

void Duelist::copyName(const char* newName) {
	name = new char[myStrlen(newName) + 1];
	myStrcpy(name, newName);
}

void Duelist::setName(const char* name) {
	if (name == nullptr || this->name == name) {
		return;
	}

	delete[] this->name;
	copyName(name);
}

void Duelist::setDeck(Deck* deck) {
	this->deck = deck;
}

void Duelist::deleteMonsterCard(size_t ind) {
	deck->deleteMonsterCard(ind);
}

void Duelist::deleteMagicCard(size_t ind) {
	deck->deleteMagicCard(ind);
}

Duelist::Duelist(const char* name, Deck* deck) : Duelist(name){
	setDeck(deck);
}

Duelist::Duelist(const char* name) {
	setName(name);
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

void Duelist::addMagicCard(const char* name, const char* effect, const Type& type) {
	deck->addMagicCard(name, effect, type);
}

void Duelist::addMonsterCard(const char* name, size_t attack, size_t defense) {
	deck->addMonsterCard(name, attack, defense);
}

void Duelist::addMagicCard(const MagicCard& magicCard) {
	deck->addMagicCard(magicCard);
}

void Duelist::addMonsterCard(const Monster& monster) {
	deck->addMonsterCard(monster);
}

size_t Duelist::getNumberOfMonsterCards() const {
	return deck->getNumberOfMonsterCards();
}

size_t Duelist::getNumberOfMagicCards() const {
	return deck->getNumberOfMagicCards();
}

void Duelist::changeMonsterCard(size_t ind, const char* name, size_t attack, size_t defense) {
	deck->changeMonsterCard(ind, name, attack, defense);
}

void Duelist::changeMagicCard(size_t ind, const char* name, const char* effect, const Type& type) {
	deck->changeMagicCard(ind, name, effect, type);
}

void Duelist::changeMonsterInDeck(size_t ind, const Monster& monster) {
	deck->changeMonsterInDeck(ind, monster);
}

void Duelist::changeMagicCardInDeck(size_t ind, const MagicCard& magicCard) {
	deck->changeMagicCardInDeck(ind, magicCard);
}

void Duelist::print() const{
	std::cout << name << std::endl;
	deck->print();
}

Duelist::~Duelist() {
	free();
}
