#include "Duelist.h"
#include <cstring>
#pragma warning (disable: 4996)

Duelist::Duelist(){
	name = new char[1];
	name[0] = '\0';
}

Duelist::Duelist(const char* name, const Deck& deck){
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->deck = deck;
}

Duelist::Duelist(const Duelist & other) {
	copy(other);
}

Duelist& Duelist::operator=(const Duelist& other){
	if(this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Duelist::~Duelist(){
	free();
}

void Duelist::copy(const Duelist& other){
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	deck = other.deck;
}

void Duelist::free(){
	delete[] name; 
}

void Duelist::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Duelist::setDeck(const Deck& deck)
{
	this->deck = deck;
}

const char* Duelist::getName() const{
	return name;
}

Deck Duelist::getDeck() const{
	return deck;
}

bool Duelist::addMonsterCard(const MonsterCard& monsterCard){
	return deck.addMonsterCardToDeck(monsterCard);
}

bool Duelist::addMagicCard(const MagicCard& magicCard){
	return deck.addMagicCardToDeck(magicCard);
}

bool Duelist::changeMonsterCardAtIndex(const MonsterCard& monsterCard,const int index){
	return deck.addMonsterCardToDeckAtIndex(monsterCard,index);
}

bool Duelist::changeMagicCardAtIndex(const MagicCard& magicCard, const int index){
	return deck.addMagicCardToDeckAtIndex(magicCard,index);
}

void Duelist::display() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Deck info: " << std::endl;
	this->deck.info();
}
