#pragma once
#include "Product.h";
#include "Order.h"

const int name_Max_Size = 25;

class Restaurant{
private:
	char name[name_Max_Size + 1];
	unsigned productsCount = 0;
	unsigned productsCapacity = 0;
	Product* list = nullptr;

public:
	Restaurant() = default;
	Restaurant(int productsCapacity, const char* name);
	Restaurant(Restaurant&&);
	Restaurant& operator=(Restaurant&&);
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);
	~Restaurant();

	const char* GetName() const;
	int GetProductsCount() const;
	int GetProductsCapacity() const;

	void AddProduct(const char* productName);
	void ReceiveOrder(const Order& order) const;

private:
	void free();
	void copyFrom(const Restaurant& other);
	void moveFrom(Restaurant&&);
};

