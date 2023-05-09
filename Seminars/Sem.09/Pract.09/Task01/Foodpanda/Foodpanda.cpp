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

void Foodpanda::AddRestaurant() {
	std::cout << "Enter restaurant name: ";
	MyString restName;
	std::cin >> restName;
	size_t restCapacity;
	std::cout << "Enter restaurant capacity: ";
	std::cin >> restCapacity;
	if (this->restaurantsCount >= this->restaurantsCapacity)
		Resize(this->restaurantsCapacity * 2);
	Restaurant rest(restName.c_str(), restCapacity);
	this->restaurants[restaurantsCount++] = rest;
}

void Foodpanda::ReadOrder() {
	std::cout << "Enter restaurant name: ";
	MyString restaurantName;
	std::cin >> restaurantName;
	int restaurantId;

	if (!ThisRestaurantExists(restaurantName.c_str(), restaurantId))
		throw std::invalid_argument("This restaurant doesn't exist!");

	std::cout << "Enter number of products in order: " << std::endl;
	size_t orderCapacity;
	std::cin >> orderCapacity;
	Order newOrder(restaurantName, orderCapacity);
	for (size_t i = 0; i < orderCapacity; i++)
	{
		std::cout << "Enter product for order: " << std::endl;
		MyString productName;
		std::cin >> productName;
		newOrder.AddProduct(productName.c_str());
	}
	this->restaurants[restaurantId].ReceiveOrder(newOrder);
}

void Foodpanda::AddNewProductsInRestaurants() {
	std::cout << "Enter restaurant name: ";
	MyString restaurantName;
	std::cin >> restaurantName;
	int restaurantId;

	if (!ThisRestaurantExists(restaurantName.c_str(), restaurantId))
		throw std::invalid_argument("This restaurant doesn't exist!");

	std::cout << "Enter products count: " << std::endl;
	size_t productsCount;
	std::cin >> productsCount;
	for (size_t i = 0; i < productsCount; i++)
	{
		std::cout << "Enter product to be added in restaurant: "
			<< this->restaurants[restaurantId].GetRestaurantName() << std::endl;
		MyString productName;
		std::cin >> productName;
		this->restaurants[restaurantId].AddProduct(productName.c_str());
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