#include "Restaurant.h"
#include <stdexcept>
#include <cstring>
#include <iostream>
#pragma warning(disable: 4996)

Restaurant::Restaurant(int productsCapacity, const char* name){
	if (productsCapacity < 0)
		throw std::out_of_range("Max products count cannot be less than 0");
	this->productsCapacity = productsCapacity;
	list = new Product[productsCapacity];

	if (name == nullptr)
		throw std::invalid_argument("The name doesn't exist");
	strcpy(this->name, name);
}

Restaurant::Restaurant(Restaurant&& other){
	moveFrom(std::move(other));
}

Restaurant& Restaurant::operator=(Restaurant&& other){
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Restaurant::Restaurant(const Restaurant& other){
	copyFrom(other);
}

Restaurant& Restaurant::operator=(const Restaurant& other){
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Restaurant::~Restaurant(){
	free();
}

const char* Restaurant::GetName() const{
	return name;
}

int Restaurant::GetProductsCount() const{
	return productsCount;
}

int Restaurant::GetProductsCapacity() const{
	return productsCapacity;
}

void Restaurant::AddProduct(const char* productName){
	if (productsCount >= productsCapacity)
		throw std::out_of_range("The list is already full");
	if (productName == nullptr)
		throw std::invalid_argument("The product doesn't exist");

	list[productsCount++] = Product(productName);
}

void Restaurant::ReceiveOrder(const Order& order) const{
	int preparation = 0;
	for (int i = 0; i < order.productsCount; i++) {
		bool hasProduct = false;
		for (int j = 0; j < productsCount; j++) {
			if (!strcmp(order.list[i].GetProduct(), list[j].GetProduct())) {
				hasProduct = true;
				preparation += 10;
				break;
			}
		}
		if (!hasProduct)
			throw std::exception("There is no such product in the restaurant");
	}
	std::cout << "The order is preparing! Needed time: " << preparation << " minutes\n";
}

void Restaurant::free(){
	delete[] list;
	list = nullptr;
	productsCount = productsCapacity = 0;
}

void Restaurant::copyFrom(const Restaurant& other){
	strcpy(name, other.name);
	productsCount = other.productsCount;
	productsCapacity = other.productsCapacity;
	list = new Product[productsCapacity];
	for (int i = 0; i < productsCount; i++)
		list[i] = other.list[i];
}

void Restaurant::moveFrom(Restaurant&& other){
	strcpy(name, other.name);
	productsCount = other.productsCount;
	productsCapacity = other.productsCapacity;
	list = std::move(other.list);
	other.list = nullptr;
	other.productsCount = other.productsCapacity = 0;
}
