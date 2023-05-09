#pragma once
#include "Restaurant.h"
class Foodpanda
{
private:
	Restaurant* restaurants = nullptr;
	size_t restaurantsCount = 0;
	size_t restaurantsCapacity = 0;

public:
	Foodpanda() = default;
	Foodpanda(size_t restaurantsCapacity);
	Foodpanda(const Foodpanda& other);
	Foodpanda& operator=(const Foodpanda& other);
	~Foodpanda();

	Foodpanda(Foodpanda&& other) noexcept;
	Foodpanda& operator=(Foodpanda&& other) noexcept;

	void AddRestaurant();
	void AddNewProductsInRestaurants();
	void ReadOrder();
private:
	void CopyFrom(const Foodpanda& other);
	void MoveFrom(Foodpanda&& other);
	void Resize(size_t newCapacity);
	void Free();

	bool ThisRestaurantExists(const char* restaurantName, int& id) const;
};

