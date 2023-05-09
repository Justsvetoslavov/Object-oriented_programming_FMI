#include "Restaurant.h"
#include <iostream>
#pragma warning (disable : 4996)
void Restaurant::CopyFrom(const Restaurant& other) {
	this->products = new Product[other.productsCapacity];
	this->productsCount = other.productsCount;
	this->productsCapacity = other.productsCapacity;
	for (size_t i = 0; i < productsCount; i++)
	{
		this->products[i] = other.products[i];
	}
	strcpy(this->name, other.name);
}

void Restaurant::Free() {
	delete[] this->products;
	this->products = nullptr;
	this->productsCount = 0;
}

Restaurant::Restaurant(const char* restaurantName, size_t capacity) {
	strcpy(this->name, restaurantName);
	this->products = new Product[capacity];
	this->productsCapacity = capacity;
}

Restaurant::Restaurant() {
	this->productsCapacity = 8;
	this->products = new Product[productsCapacity];
}

Restaurant::Restaurant(const Restaurant& other) {
	CopyFrom(other);
}
Restaurant& Restaurant::operator=(const Restaurant& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}
Restaurant::~Restaurant() {
	Free();
}

void Restaurant::Resize(size_t newCapacity) {
	Product* temp = this->products;
	this->products = new Product[newCapacity];
	for (size_t i = 0; i < this->productsCount; i++)
	{
		this->products[i] = temp[i];
	}
	this->productsCapacity = newCapacity;
	delete[] temp;
}

void Restaurant::AddProduct(const MyString& productName) {
	if (this->productsCount >= this->productsCapacity)
		Resize(this->productsCapacity * 2);
	Product newProduct(productName);
	this->products[productsCount++] = newProduct;
}

void Restaurant::MoveFrom(Restaurant&& other) {
	this->products = other.products;
	other.products = nullptr;

	other.productsCount = 0;
	other.productsCapacity = 0;
}

Restaurant::Restaurant(Restaurant&& other) noexcept {
	MoveFrom(std::move(other));
}
Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
	if (this != &other) {
		Free();
		MoveFrom(std::move(other));
	}
	return *this;
}

void Restaurant::ReceiveOrder(const Order& order) {
	if (strcmp(this->name, order.GetRestaurantName()))
		throw std::invalid_argument("This order is not for this restaurant!");

	bool foundItem = false;
	for (size_t i = 0; i < order.GetProductsCount(); i++)
	{
		for (size_t j = 0; j < this->productsCount; j++)
		{
			if (!strcmp(order.GetProducts()[i].GetProductName().c_str(),
				this->products[j].GetProductName().c_str()))
				foundItem = true;
		}
		if (!foundItem)
			throw std::invalid_argument("This restaurant do not have one of these products!");
	}
	std::cout << "Order received! Estimated time for delivery: "
		<< std::rand() << " minutes" << std::endl;
}

const char* Restaurant::GetRestaurantName() const {
	return this->name;
}
