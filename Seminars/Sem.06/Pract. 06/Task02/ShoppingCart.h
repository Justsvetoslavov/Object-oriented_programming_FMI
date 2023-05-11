#pragma once
#include "Item.h"

class ShoppingCart
{
private:
	Item* items = nullptr;
	size_t itemsCount = 0;
	size_t cartCapacity = 0;

public:
	ShoppingCart();
	ShoppingCart(const ShoppingCart& other);
	ShoppingCart& operator=(const ShoppingCart& other);
	~ShoppingCart();

	bool AddItem(const Item& item);
	bool RemoveItem(const char* name);
	size_t ItemsCount() const;
	bool Exists(const char* name) const;
	bool IsEmpty() const;
	double GetPriceOf(const char* name) const;
	double TotalPrice() const;
	void SortByName();
	bool Save(const char* name) const;

private:
	void CopyFrom(const ShoppingCart& other);
	void Free();
	void Resize(size_t newCapacity);
	size_t Find(const char* name) const;
};