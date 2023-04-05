#pragma once

#include <fstream>

class Item {
	char* name = nullptr;
	size_t numberOfAvailableItems = 0;
	double price = 0;

	void free();
	void copyFrom(const Item& other);
	void copyName(const char* newName);

public:
	Item() = default;
	Item(const char* name, size_t numberOfAvailableItems, double price);
	Item(const Item& other);

	Item& operator=(const Item& other);

	void setName(const char* name);
	void setNumberOfAvailableItems(size_t numberOfAvailableItems);
	void setPrice(double price);

	const char* getName() const;
	size_t getNumberOfAvailableItems() const;
	double getPrice() const;

	void print() const;
	void save(std::ofstream& ofs) const;

	~Item();
};

void swapItems(Item& i1, Item& i2);