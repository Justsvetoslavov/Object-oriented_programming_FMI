#include "Foodpanda.h"
void Foodpanda::CopyFrom(const Foodpanda& other) {
	this->restaurants = new Restaurant[other.restaurantsCount];
	for (size_t i = 0; i < other.restaurantsCount; i++)
	{
		this->restaurants[i] = other.restaurants[i];
	}
	this->restaurantsCapacity = other.restaurantsCapacity;
	this->restaurantsCount = other.restaurantsCount;
}
void Foodpanda::MoveFrom(Foodpanda&& other) {
	this->restaurants = other.restaurants;
	this->restaurantsCapacity = other.restaurantsCapacity;
	this->restaurantsCount = other.restaurantsCount;
	other.restaurants = nullptr;
	other.restaurantsCapacity = 0;
	other.restaurantsCount = 0;
}
void Foodpanda::Free() {
	delete[] this->restaurants;
	this->restaurants = nullptr;
	this->restaurantsCapacity = 0;
	this->restaurantsCount = 0;
}
Foodpanda::Foodpanda(size_t restaurantsCapacity) {
	this->restaurants = new Restaurant[restaurantsCapacity];
	this->restaurantsCapacity = restaurantsCapacity;
}
Foodpanda::Foodpanda(const Foodpanda& other) {
	CopyFrom(other);
}
Foodpanda& Foodpanda::operator=(const Foodpanda& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}
Foodpanda::~Foodpanda() {
	Free();
}

Foodpanda::Foodpanda(Foodpanda&& other) noexcept {
	MoveFrom(std::move(other));
}
Foodpanda& Foodpanda::operator=(Foodpanda&& other) noexcept {
	if (this != &other) {
		Free();
		MoveFrom(std::move(other));
	}
	return *this;
}

void Foodpanda::Resize(size_t newCapacity) {
	Restaurant* temp = this->restaurants;
	this->restaurants = new Restaurant[newCapacity];
	for (size_t i = 0; i < this->restaurantsCount; i++)
	{
		this->restaurants[i] = temp[i];
	}
	this->restaurantsCapacity = newCapacity;
	delete[] temp;
}

void Foodpanda::AddRestaurant(const MyString& restaurantName, size_t restaurantCapacity) {
	if (this->restaurantsCount >= this->restaurantsCapacity)
		Resize(this->restaurantsCapacity * 2);

	Restaurant rest(restaurantName.c_str(), restaurantCapacity);
	this->restaurants[restaurantsCount++] = std::move(rest);
}

void Foodpanda::ReadOrder(const MyString& restaurantName, const Order& newOrder) {
	int restaurantId;
	if (!ThisRestaurantExists(restaurantName.c_str(), restaurantId)) {
		std::cout << "This restaurant doesn't exist!" << std::endl;
		return;
	}
	this->restaurants[restaurantId].ReceiveOrder(newOrder);
}

void Foodpanda::AddNewProductsInRestaurant(const MyString& restaurantName, 
	const MyString* products, size_t productsCount) {
	int restaurantId;
	if (!ThisRestaurantExists(restaurantName.c_str(), restaurantId))
		throw std::invalid_argument("This restaurant doesn't exist!");

	for (size_t i = 0; i < productsCount; i++)
	{
		this->restaurants[restaurantId].AddProduct(products[i].c_str());
	}
}

bool Foodpanda::ThisRestaurantExists(const char* restaurantName, int& id) const {
	for (size_t i = 0; i < this->restaurantsCount; i++)
	{
		if (!strcmp(this->restaurants[i].GetRestaurantName(), restaurantName)) {
			id = i;
			return true;
		}
	}
	return false;
}