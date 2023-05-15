#pragma once
#include "MyString.h"
#include "Product.h"
class Order
{
private:
	Product* products = nullptr;
	MyString restaurantName;
	size_t productsCount = 0;
	size_t productsCapacity = 0;

public:
	Order() = default;
	Order(const MyString& restaurantName, size_t productCapacity);
	Order(const Order& other);
	Order& operator=(const Order& other);

	Order(Order&& other) noexcept;
	Order& operator=(Order&& other) noexcept;
	~Order();

	void AddProduct(const char* productName);
	const char* GetRestaurantName() const;
	const Product* GetProducts() const;
	size_t GetProductsCount() const;

	void ReceiveOrder(const Order& order);
private:
	void CopyFrom(const Order& other);
	void MoveFrom(Order&& other);
	void Resize(size_t newCapacity);
	void Free();
};