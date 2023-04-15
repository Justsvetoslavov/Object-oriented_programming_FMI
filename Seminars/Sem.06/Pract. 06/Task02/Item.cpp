#include "Item.h"
#include <cstring>
#pragma warning(disable: 4996)

Item::Item() : Item("Unkown", 0, 0){}

Item::Item(const char* name, bool isAvailable, double price) {
	SetName(name);
	SetAvailability(isAvailable);
	SetPrice(price);
}

Item::Item(const Item& other){
	copyFrom(other);
}

Item& Item::operator=(const Item& other){
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Item::~Item(){
	free();
}

void Item::SetName(const char* name) {
	if (name == nullptr)
		return;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Item::SetAvailability(bool isAvailable) {
	this->isAvailable = isAvailable;
}

void Item::SetPrice(double price) {
	if (price < 0)
		price = 0;
	this->price = price;
}

const char* Item::GetName() const{
	return name;
}

bool Item::GetAvailability() const{
	return isAvailable;
}

double Item::GetPrice() const{
	return price;
}

void Item::copyFrom(const Item& other){
	SetName(other.name);
	SetAvailability(other.isAvailable);
	SetPrice(other.price);
}

void Item::free(){
	delete[] name;
	name = nullptr;
	isAvailable = false;
	price = 0;
}
