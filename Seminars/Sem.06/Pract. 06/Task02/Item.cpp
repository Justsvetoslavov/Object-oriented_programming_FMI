#include "Item.h"

#include <iostream>
#include <fstream>

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

void Item::free() {
	delete[] name;
}

void Item::copyFrom(const Item& other) {
	copyName(other.name);
	numberOfAvailableItems = other.numberOfAvailableItems;
	price = other.price;
}

void Item::copyName(const char* newName) {
	name = new char[myStrlen(newName) + 1];
	myStrcpy(name, newName);
}

Item::Item(const char* name, size_t numberOfAvailableItems, double price) {
	copyName(name);
	setNumberOfAvailableItems(numberOfAvailableItems);
	setPrice(price);
}

Item::Item(const Item& other) {
	copyFrom(other);
}

Item& Item::operator=(const Item& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}


void Item::setName(const char* name) {
	delete[] this->name;
	copyName(name);
}

void Item::setNumberOfAvailableItems(size_t numberOfAvailableItems) {
	this->numberOfAvailableItems = numberOfAvailableItems;
}

void Item::setPrice(double price) {
	if (price < 0) {
		return;
	}
	this->price = price;
}

const char* Item::getName() const {
	return name;
}

size_t Item::getNumberOfAvailableItems() const {
	return numberOfAvailableItems;
}

double Item::getPrice() const {
	return price;
}

void Item::print() const {
	std::cout << name << " " << numberOfAvailableItems << " " << price;
}

void Item::save(std::ofstream& ofs) const{
	if (!ofs.is_open()) {
		return;
	}

	ofs << name << ',' << numberOfAvailableItems << ',' << price;
}

Item::~Item() {
	free();
}

void swapItems(Item& i1, Item& i2) {
	Item temp = i1;
	i1 = i2;
	i2 = temp;
}

