#pragma once
#include "Item.h"
#include <iostream>

class ShoppingCart{
private:
	Item* items = nullptr;
	int itemsCount = 0;
	int maxItemsCount = 0;

public:
	ShoppingCart();
	ShoppingCart(const ShoppingCart& cart);
	ShoppingCart& operator=(const ShoppingCart& cart);
	~ShoppingCart();

	bool AddItem(const Item& item);
	bool RemoveItem(const char* name);
	int ItemsCount() const;
	bool Exists(const char* name) const;
	bool IsEmpty() const;
	double GetPriceOf(const char* name) const;
	double TotalPrice() const;
	void SortByName();
	bool Save(const char* fileName) const;

private:
	void copyFrom(const ShoppingCart& cart);
	void free();
	void IncreaseItemsCount();
	void Resize();
	int Find(const char* name) const;
};

