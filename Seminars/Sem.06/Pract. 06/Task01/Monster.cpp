#include "Monster.h"

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

Monster::Monster(const char* name, size_t attack, size_t defense) {
	copyName(name);
	setAttack(attack);
	setDefense(defense);
}

Monster::Monster(const Monster& other) {
	copyFrom(other);
}

Monster Monster::operator=(const Monster& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Monster::~Monster() {
	free();
}

void Monster::copyFrom(const Monster& other) {
	copyName(other.name);
	this->attack = other.attack;
	this->defense = other.defense;
}

void Monster::free() {
	delete[] name;
	name = nullptr;
	attack = defense = 0;
}

void Monster::copyName(const char* newName) {
	name = new char[myStrlen(newName) + 1];
	myStrcpy(name, newName);
}

void Monster::setName(const char* name) {
	if (name == nullptr || this->name == name) {
		return;
	}

	delete[] this->name;
	copyName(name);
}

void Monster::setAttack(size_t attack) {
	this->attack = attack;
}

void Monster::setDefense(size_t defense) {
	this->defense = defense;
}

const char* Monster::getName() const {
	return name;
}

size_t Monster::getAttack() const {
	return attack;
}

size_t Monster::getDefense() const {
	return defense;
}

void Monster::print() const {
	std::cout << name << " " << attack << " " << defense << std::endl;
}

