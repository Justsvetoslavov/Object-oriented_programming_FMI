#pragma once
#include "MyString.h"
#include "Product.h"

class Order{
private:
	MyString restaurantName;
	unsigned maxProductsCount = 0;
	unsigned productsCount = 0;
	Product* list;

public:
	Order() = default;
	Order(const char* restaurantName, int maxProductsCount);
	Order(Order&& other);
	Order(const Order& other);
	Order& operator=(Order&& other);
	Order& operator=(const Order& other);
	~Order();

	const char* GetName() const;

	void AddProduct(const char* productName);
	friend class Restaurant;
private:
	void free();
	void copyFrom(const Order& other);
	void moveFrom(Order&& other);
};

