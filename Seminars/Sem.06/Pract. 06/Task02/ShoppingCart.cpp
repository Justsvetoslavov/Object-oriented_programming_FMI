#include "ShoppingCart.h"
#include <iostream>
#include <fstream>

void ShoppingCart::CopyFrom(const ShoppingCart& other) {
	this->items = new Item[other.itemsCount];
	for (size_t i = 0; i < other.itemsCount; i++)
	{
		this->items[i] = other.items[i];
	}
	this->itemsCount = other.itemsCount;
	this->cartCapacity = other.cartCapacity;
}
void ShoppingCart::Free() {
	delete[] items;
	this->items = nullptr;
	this->itemsCount = 0;
	this->cartCapacity = 0;
}
ShoppingCart::ShoppingCart()  {
	this->cartCapacity = 9;
	this->items = new Item[cartCapacity];
	this->itemsCount = 0;
}
ShoppingCart::ShoppingCart(const ShoppingCart& other) {
	CopyFrom(other);
}
ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return (*this);
}
ShoppingCart::~ShoppingCart() {
	Free();
}
void ShoppingCart::Resize(size_t newCapacity){
	Item* temp = this->items;
	this->items = new Item[newCapacity];
	for (size_t i = 0; i < itemsCount; i++)
	{
		temp[i] = this->items[i];
	}
	this->cartCapacity = newCapacity;
	delete[] temp;
}
size_t ShoppingCart::Find(const char* name) const {
	if (!name)
		return -1;

	for (size_t i = 0; i < itemsCount; i++)
	{
		if (!strcmp(this->items[i].GetName(), name))
			return i;
	}

	return -1;
}

bool ShoppingCart::AddItem(const Item& item) {
	if (this->itemsCount >= this->cartCapacity)
		this->Resize(this->cartCapacity * 2);

	size_t itemIdWithSameName = Find(item.GetName());

	if (itemIdWithSameName != -1)
		return false;

	this->items[itemsCount++] = item;
	return true;
}

bool ShoppingCart::RemoveItem(const char* name) {
	if (!name)
		return false;

	size_t itemId = Find(name);

	if (itemId == -1)
		return false;

	for (size_t i = itemId; i < itemsCount - 1; i++)
	{
		this->items[i] = this->items[i + 1];
	}

	this->itemsCount--;
	return true;
}

size_t ShoppingCart::ItemsCount() const {
	return this->itemsCount;
}

bool ShoppingCart::Exists(const char* name) const {
	if (!name)
		return false;

	if (Find(name) == -1)
		return false;

	return true;
}

bool ShoppingCart::IsEmpty() const {
	return this->itemsCount == 0;
}

double ShoppingCart::GetPriceOf(const char* name) const {
	if (!name)
		return 0.0;

	size_t itemId = Find(name);
	if (itemId == -1)
		return 0.0;

	return this->items[itemId].GetPrice();
}

double ShoppingCart::TotalPrice() const {
	if (this->itemsCount == 0)
		return 0.0;

	double sum = 0;
	for (size_t i = 0; i < itemsCount; i++)
	{
		sum += this->items[i].GetPrice();
	}

	return sum;
}

void ShoppingCart::SortByName() {
	for (size_t i = 0; i < this->itemsCount - 1; i++)
	{
		int minId = i;
		for (size_t j = i + 1; j < this->itemsCount; j++)
		{
			if (strcmp(this->items[minId].GetName(), this->items[j].GetName()) > 0)
				minId = j;
		}
		if (minId != i)
			std::swap(this->items[minId], this->items[i]);
	}
}

bool ShoppingCart::Save(const char* name) const {
	std::ofstream writeFile(name, std::ios::out);

	if (!writeFile.is_open()) {
		std::cout << "Error opening file!" << std::endl;
		return false;
	}

	writeFile << "Name, Amount, Price" << std::endl;

	for (size_t i = 0; i < itemsCount; i++)
	{
		this->items[i].SaveItem(writeFile);
	}
	writeFile.close();
	return true;
}
