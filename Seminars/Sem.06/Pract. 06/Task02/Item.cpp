#include "Item.h"
#include <cstring>
#pragma warning (disable : 4996)

void Item::CopyFrom(const Item& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->price = other.price;
	this->isAvailable = other.isAvailable;
}
void Item::Free() {
	delete[] name;
	this->name = nullptr;
	this->isAvailable = false;
	this->price = 0;
}
Item::Item(const char* name, bool isAvailable, double price) {
	SetName(name);
	SetAvailability(isAvailable);
	SetPrice(price);
}
Item& Item::operator=(const Item& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return (*this);
}
Item::Item(const Item& other) {
	CopyFrom(other);
}
Item::~Item() {
	Free();
}
void Item::SetName(const char* name) {
	if (!name)
		return;

	if (this->name)
		delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Item::SetAvailability(bool availability) {
	this->isAvailable = availability;
}
void Item::SetPrice(double price) {
	if (price < 0)
		return;

	this->price = price;
}
const char* Item::GetName() const {
	return this->name;
}
bool Item::IsAvailable() const {
	return this->isAvailable;
}
double Item::GetPrice() const {
	return this->price;
}
void Item::SaveItem(std::ofstream& writeFile) const {
	writeFile << this->name << ", " << this->isAvailable << ", " << this->price << std::endl;
}