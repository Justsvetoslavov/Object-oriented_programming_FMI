#pragma once

#include "Item.h"

const int START_SIZE = 16;

class ShoppingCart {
	// Items exist independently. 
	Item** items = nullptr;
	// The number of items from each type 
	size_t* amounts = nullptr; 

	size_t numberOfItems = 0;
	size_t maxSize = START_SIZE;

	void copyFrom(const ShoppingCart& other);
	void free();

	void resize();
	int find(const char* itemName) const;

	bool validateItemToAdd(const Item& item, size_t amount) const;

	void setAmounts(size_t* amounts, size_t numberOfItems);
	void copyAmounts(size_t* amounts, size_t numberOfItems);
	void copyItems(Item** items, size_t numberOfItems);

public:
	ShoppingCart();
	ShoppingCart(Item** items, size_t* amounts, size_t numberOfItems);
	ShoppingCart(const ShoppingCart& other);

	ShoppingCart& operator=(const ShoppingCart& other);

	bool addItem(Item& item, size_t amount);
	bool removeItem(const char* name);
	size_t itemsCount() const;
	bool exists(const char* itemName) const;

	bool isEmpty() const;

	double getPriceOf(const char* itemName) const;
	double totalPrice() const;

	void sortByName();

	bool save(const char* fileName) const;
	void print() const;

	~ShoppingCart();
};