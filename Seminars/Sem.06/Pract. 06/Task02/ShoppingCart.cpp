#include "ShoppingCart.h"
#include <iostream>
#include <cstring>
#include <fstream>

ShoppingCart::ShoppingCart() {
	maxItemsCount = 5;
	items = new Item[maxItemsCount];
}

ShoppingCart::ShoppingCart(const ShoppingCart& cart) {
	copyFrom(cart);
}

ShoppingCart& ShoppingCart::operator=(const ShoppingCart& cart) {
	if (this != &cart) {
		free();
		copyFrom(cart);
	}
	return *this;
}

ShoppingCart::~ShoppingCart() {
	free();
}

void ShoppingCart::IncreaseItemsCount() {
	if (itemsCount + 1 > maxItemsCount)
		Resize();
	itemsCount++;
}

bool ShoppingCart::AddItem(const Item& item) {
	for (int i = 0; i < itemsCount; i++) {
		if (!strcmp(items[i].GetName(), item.GetName())) 
			return false;
	}

	items[itemsCount] = item;
	IncreaseItemsCount();
	return true;
}

bool ShoppingCart::RemoveItem(const char* name) {
	if (name == nullptr)
		return false;

	for (int i = 0; i < itemsCount; i++) {
		if (!strcmp(items[i].GetName(), name)) {
			for (int j = i; j < itemsCount - 1; j++) 
				items[j] = items[j + 1];
			itemsCount--;
			return true;
		}
	}

	return false;
}

int ShoppingCart::ItemsCount() const {
	return itemsCount;
}

bool ShoppingCart::Exists(const char* name) const {
	return (Find(name) != -1) ? true : false;
}

bool ShoppingCart::IsEmpty() const {
	return (itemsCount > 0) ? false : true;
}

double ShoppingCart::GetPriceOf(const char* name) const {
	int index = Find(name);

	if (index == -1) 
		return 0.0;

	return items[index].GetPrice();
}

double ShoppingCart::TotalPrice() const {
	double totalPrice = 0;

	for (int i = 0; i < itemsCount; i++) {
		totalPrice += items[i].GetPrice();
	}

	return totalPrice;
}

void ShoppingCart::SortByName() {
	for (int i = 0; i < itemsCount - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < itemsCount; j++) {
			if (strcmp(items[minIndex].GetName(), items[j].GetName()) > 0) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			Item temp(items[minIndex]);
			items[minIndex] = items[i];
			items[i] = temp;
		}
	}
}

bool ShoppingCart::Save(const char* fileName) const {
	if (fileName == nullptr)
		return false;

	std::ofstream file(fileName);
	if (!file.is_open())
		return false;

	for (int i = 0; i < itemsCount; i++) {
		file << items[i].GetName() << ',';
		file << items[i].GetAvailability() << ',';
		file << items[i].GetPrice() << std::endl;
	}

	file.close();
	return true;
}

int ShoppingCart::Find(const char* name) const {
	if (name == nullptr)
		return -1;

	for (int i = 0; i < itemsCount; i++) {
		if (!strcmp(items[i].GetName(), name))
			return i;
	}

	return -1;
}

void ShoppingCart::copyFrom(const ShoppingCart& cart) {
	if (cart.items == nullptr)
		return;
	items = new Item[cart.maxItemsCount];
	itemsCount = cart.itemsCount;
	maxItemsCount = cart.maxItemsCount;
	for (int i = 0; i < itemsCount; i++) {
		items[i] = cart.items[i];
	}
}

void ShoppingCart::free() {
	delete[] items;
	items = nullptr;
	maxItemsCount = 0;
	itemsCount = 0;
}

void ShoppingCart::Resize() {
	maxItemsCount *= 2;
	Item* newItems = new Item[maxItemsCount];
	for (int i = 0; i < itemsCount; i++)
		newItems[i] = items[i];
	delete[] items;
	items = newItems;
}