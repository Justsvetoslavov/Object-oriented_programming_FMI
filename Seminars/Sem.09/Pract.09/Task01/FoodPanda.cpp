#include "FoodPanda.h"

FoodPanda::FoodPanda(int maxRestaurantsCount) {
	if (maxRestaurantsCount < 0)
		throw std::out_of_range("The capacity of the restaurants cannot be less than 0");

	this->maxRestaurantsCount = maxRestaurantsCount;
	restaurants = new Restaurant[maxRestaurantsCount];
}

FoodPanda::FoodPanda(const FoodPanda& other) {
	copyFrom(other);
}

FoodPanda::FoodPanda(FoodPanda&& other) {
	moveFrom(std::move(other));
}

FoodPanda& FoodPanda::operator=(const FoodPanda& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

FoodPanda& FoodPanda::operator=(FoodPanda&& other) {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

FoodPanda::~FoodPanda() {
	free();
}

void FoodPanda::AddRestaurant(const char* restaurantName, int productsCapacity) {
	if (restaurantName == nullptr)
		throw std::invalid_argument("Restaurant name doesn't exist");

	if (restaurantsCount >= maxRestaurantsCount)
		throw std::out_of_range("The capacity for the restaurants has been reached");

	restaurants[restaurantsCount++] = Restaurant(productsCapacity, restaurantName);
}

void FoodPanda::AddProduct(const char* restaurantName, const char* productName){
	if (restaurantName == nullptr || productName == nullptr)
		throw std::invalid_argument("The name doesn't exist");

	for (int i = 0; i < restaurantsCount; i++) {
		if (!strcmp(restaurants[i].GetName(), restaurantName)) {
			if(restaurants[i].GetProductsCount() >= restaurants[i].GetProductsCapacity())
				throw std::out_of_range("The list is already full");
			restaurants[i].AddProduct(productName);
			return;
		}
	}
	throw std::invalid_argument("There is no restaurant with that name");
}

void FoodPanda::TakeOrder(const Order& order){
	for (int i = 0; i < restaurantsCount; i++) {
		if (!strcmp(restaurants[i].GetName(), order.GetName())) {
			restaurants[i].ReceiveOrder(order);
			return;
		}
	}
	throw std::invalid_argument("There is no restaurant with that name");
}

void FoodPanda::free() {
	delete[] restaurants;
	restaurants = nullptr;
	maxRestaurantsCount = restaurantsCount = 0;
}

void FoodPanda::copyFrom(const FoodPanda& other) {
	maxRestaurantsCount = other.maxRestaurantsCount;
	restaurantsCount = other.restaurantsCount;
	restaurants = new Restaurant[maxRestaurantsCount];
}

void FoodPanda::moveFrom(FoodPanda&& other) {
	restaurants = std::move(other.restaurants);
	other.restaurants = nullptr;
	maxRestaurantsCount = other.maxRestaurantsCount;
	restaurantsCount = other.restaurantsCount;
	other.restaurantsCount = other.maxRestaurantsCount = 0;
}
