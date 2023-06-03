#pragma once
#include "Product.h"
#include "Order.h"
const int NAME_MAX_SIZE = 25;
class Restaurant
{
private:
	Product* products;
	char name[NAME_MAX_SIZE + 1];
	size_t productsCount = 0;
	size_t productsCapacity = 0;

public:
	Restaurant();
	Restaurant(const char* restaurantName, size_t capacity);
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);

	Restaurant(Restaurant&& other) noexcept;
	Restaurant& operator=(Restaurant&& other) noexcept;

	~Restaurant();

	void AddProduct(const MyString& productName);
	void ReceiveOrder(const Order& order);

	const char* GetRestaurantName() const;

private:
	void CopyFrom(const Restaurant& other);
	void Free();
	void MoveFrom(Restaurant&& other);
	void Resize(size_t newCapacity);
};

