#include "MonsterCard.h"
#include <cstring>
#pragma warning(disable: 4996)

MonsterCard::MonsterCard() : MonsterCard("Unknown", 0, 0){}

MonsterCard::MonsterCard(const char* name, int attackPoints, int defensePoints) {
	SetName(name);
	SetAttackPoints(attackPoints);
	SetDefensePoints(defensePoints);
}

void MonsterCard::SetName(const char* name) {
	if (name == nullptr)
		return;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void MonsterCard::SetAttackPoints(int points){
	if (points < 0)
		points = 0;
	attackPoints = points;
}

void MonsterCard::SetDefensePoints(int points) {
	if (points < 0)
		points = 0;
	defensePoints = points;
}

void MonsterCard::copyFrom(const MonsterCard& other) {
	SetName(other.name);
	SetAttackPoints(other.attackPoints);
	SetDefensePoints(other.defensePoints);
}

void MonsterCard::free(){
	delete[] name;
	name = nullptr;
	attackPoints = defensePoints = 0;
}

MonsterCard::MonsterCard(const MonsterCard& other){
	copyFrom(other);
}

MonsterCard& MonsterCard::operator=(const MonsterCard& other){
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MonsterCard::~MonsterCard(){
	free();
}
