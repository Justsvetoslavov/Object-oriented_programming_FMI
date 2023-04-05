#include "MagicCard.h"

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

MagicCard::MagicCard() {
	setName(DEFAULT_NAME);
	setEffect(DEFAULT_EFFECT);
}

MagicCard::MagicCard(const char* name, const char* effect, const Type& type) {
	setName(name);
	setEffect(effect);
	setType(type);
}

void MagicCard::setName(const char* name) {
	size_t nameLen = myStrlen(name);

	if (name == nullptr || nameLen > MAX_NAME_LEN || this->name == name) {
		return;
	}

	myStrcpy(this->name, name);
}

void MagicCard::setEffect(const char* effect) {
	size_t effectLen = myStrlen(effect);

	if (effect == nullptr || effectLen > MAX_EFFECT_LEN || this->effect == effect) {
		return;
	}

	myStrcpy(this->effect, effect);
}

void MagicCard::setType(const const Type& type) {
	this->type = type;
}

const char* MagicCard::getName() const {
	return name;
}

const char* MagicCard::getEffect() const {
	return effect;
}

const Type& MagicCard::getType() const {
	return type;
}

void MagicCard::print() const{
	std::cout << name << " " << effect << " " << (int)type << "\n";
}