#include "MonsterCard.h"
#include <cstring>
#pragma warning (disable : 4996)

MonsterCard::MonsterCard() : MonsterCard("", 0, 0) {}

void MonsterCard::CopyName(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void MonsterCard::CopyFrom(const MonsterCard& other) {
	CopyName(other.name);
	this->attackPoints = other.attackPoints;
	this->defensePoints = other.defensePoints;
}
void MonsterCard::Free() {
	delete[] this->name;
	this->name = nullptr;
	this->attackPoints = 0;
	this->defensePoints = 0;
}

MonsterCard::MonsterCard(const char* name, unsigned attackPoints, unsigned defensePoints) {
	SetName(name);
	SetAttackPoints(attackPoints);
	SetDefensePoints(defensePoints);
}
MonsterCard::MonsterCard(const MonsterCard& other) {
	CopyFrom(other);
}
MonsterCard& MonsterCard::operator=(const MonsterCard& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}

	return (*this);
}
MonsterCard::~MonsterCard() {
	Free();
}

const char* MonsterCard::GetName() const {
	return this->name;
}
unsigned MonsterCard::GetAttackPoints() const {
	return this->attackPoints;
}
unsigned MonsterCard::GetDefensePoints() const {
	return this->defensePoints;
}

void MonsterCard::SetName(const char* name) {
	if (!name)
		return;

	if (this->name)
		delete[] name;

	CopyName(name);
}
void MonsterCard::SetAttackPoints(unsigned attackPoints) {
	if (attackPoints < 0)
		return;

	this->attackPoints = attackPoints;
}
void MonsterCard::SetDefensePoints(unsigned defensePoints) {
	if (defensePoints < 0)
		return;

	this->defensePoints = defensePoints;
}