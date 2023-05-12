#pragma once
#include "Restaurant.h"
#include "Order.h"

class FoodPanda {
private:
	Restaurant* restaurants = nullptr;
	unsigned maxRestaurantsCount = 0;
	unsigned restaurantsCount = 0;

public:
	FoodPanda() = default;
	FoodPanda(int maxRestaurantsCount);
	FoodPanda(const FoodPanda& other);
	FoodPanda(FoodPanda&& other);
	FoodPanda& operator=(const FoodPanda& other);
	FoodPanda& operator=(FoodPanda&& other);
	~FoodPanda();

	void AddRestaurant(const char* restaurantName, int productsCapacity);
	void AddProduct(const char* restaurantName, const char* productName);
	void TakeOrder(const Order& order);

private:
	void free();
	void copyFrom(const FoodPanda& other);
	void moveFrom(FoodPanda&& other);
};

