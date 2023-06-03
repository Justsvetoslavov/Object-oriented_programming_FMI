#include "Order.h"

Order::Order(const char* restaurantName, int maxProductsCount){
	if (restaurantName == nullptr)
		throw std::invalid_argument("The name of the restaurant doesn't exist");

	this->restaurantName = restaurantName;
	this->maxProductsCount = maxProductsCount;
	list = new Product[maxProductsCount];
}

Order::Order(Order&& other){
	moveFrom(std::move(other));
}

Order::Order(const Order& other){
	copyFrom(other);
}

Order& Order::operator=(Order&& other){
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Order& Order::operator=(const Order& other){
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Order::~Order(){
	free();
}

const char* Order::GetName() const{
	return restaurantName.c_str();
}

void Order::AddProduct(const char* productName){
	if (productsCount >= maxProductsCount)
		throw std::out_of_range("The list is already full");
	if (productName == nullptr)
		throw std::invalid_argument("The product doesn't exist");

	list[productsCount++] = Product(productName);
}

void Order::free(){
	delete[] list;
	list = nullptr;
	productsCount = maxProductsCount = 0;
}

void Order::copyFrom(const Order& other){
	restaurantName = other.restaurantName;
	maxProductsCount = other.maxProductsCount;
	productsCount = other.productsCount;
	list = new Product[productsCount];
}

void Order::moveFrom(Order&& other){
	restaurantName = std::move(other.restaurantName);
	other.restaurantName = nullptr;
	productsCount = other.productsCount;
	maxProductsCount = other.maxProductsCount;
	other.productsCount = other.maxProductsCount = 0;
}
