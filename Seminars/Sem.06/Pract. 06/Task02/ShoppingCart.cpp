#include "ShoppingCart.h"

#include <iostream>
#include <fstream>

const char* ITEM_EXISTS_ERROR = "The item already exists";
const char* ITEM_NOT_FOUND_ERROR = "Item not found";
const char* FILE_NOT_OPEN_ERR = "Couldn't open file";
const char* ITEM_NOT_AVAILABLE_ERR = "Item not available";
const char* AMOUNT_ERR = "The amount of items you are trying to add is too high.";

const char* ITEM_FOUND_MSG = "Item found";

namespace {
	size_t myStrlen(const char* str) {
		if (str == nullptr) {
			return 0;
		}

		size_t ctr = 0;
		while (*str) {
			str++;
			ctr++;
		}

		return ctr;
	}

	void myStrcpy(char* dest, const char* src) {
		if (src == nullptr || dest == nullptr) {
			return;
		}

		while (*src) {
			*(dest) = *(src);
			src++;
			dest++;
		}

		*(dest) = '\0';
	}

	int myStrcmp(const char* str1, const char* str2) {
		if (str1 == nullptr || str2 == nullptr) {
			return 0;
		}

		while (*str1 && *str2) {
			if (*str1 < *str2) {
				return -1;
			}

			if (*str1 > *str2) {
				return 1;
			}

			str1++;
			str2++;
		}
		// The loop was exited because one of the strings ended 
		// This will return true if they both ended at the same time (*str1 == *str2 == '\0')
		if (*str1 == *str2) {
			return 0;
		}

		// First string is longer
		if (*str1) {
			return 1;
		}

		// Second string is longer
		return -1;
		
	}

	size_t getMinNameIndex(const Item** items, size_t numberOfItems) {
		size_t minInd = 0;
		for (int i = 1; i < numberOfItems; i++) {
			if (myStrcmp((*items[i]).getName(), (*items[minInd]).getName()) < 0) {
				minInd = i;
			}
		}
		return minInd;
	}
}

ShoppingCart::ShoppingCart() {
	items = new Item * [START_SIZE];
	amounts = new size_t[START_SIZE];
}

void ShoppingCart::copyFrom(const ShoppingCart& other) {
	copyItems(other.items, other.numberOfItems);
	copyAmounts(other.amounts, other.numberOfItems);

	numberOfItems = other.numberOfItems;
	maxSize = other.maxSize;
}

void ShoppingCart::free() {
	// Delete the array of pointers but not the actual items 
	delete[] items;
	items = nullptr;

	delete[] amounts;
	amounts = nullptr;

	numberOfItems = maxSize = 0;
}

void ShoppingCart::resize() {
	maxSize *= 2;
	Item** newItems = new Item*[maxSize];
	size_t* newAmounts = new size_t[maxSize];

	for (int i = 0; i < numberOfItems; i++) {
		newItems[i] = items[i];
		newAmounts[i] = amounts[i];
	}

	delete[] items;
	delete[] amounts;

	items = newItems;
	amounts = newAmounts;
}

int ShoppingCart::find(const char* itemName) const{
	for (int i = 0; i < numberOfItems; i++) {
		if (myStrcmp(itemName, (*items[i]).getName()) == 0) {
			return i;
		}
	}
	return -1;
}

ShoppingCart::ShoppingCart(Item** items, size_t* amounts, size_t numberOfItems) {
	copyItems(items, numberOfItems);
	copyAmounts(amounts, numberOfItems);
	this->numberOfItems = numberOfItems;
}

ShoppingCart::ShoppingCart(const ShoppingCart& other) {
	copyFrom(other);
}

ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

bool ShoppingCart::validateItemToAdd(const Item& item, size_t amount) const {
	// Item isn't available
	if (item.getNumberOfAvailableItems() == 0) {
		std::cout << ITEM_NOT_AVAILABLE_ERR << std::endl;
		return false;
	}

	// The amount is too high
	if (amount > item.getNumberOfAvailableItems()) {
		std::cout << AMOUNT_ERR << std::endl;
		return false;
	}

	// Item aready exists
	int foundInd = find(item.getName());
	if (foundInd != -1) {
		std::cout << ITEM_EXISTS_ERROR << std::endl;
		return false;
	}
}

bool ShoppingCart::addItem(Item& item, size_t amount) {
	if(!validateItemToAdd(item, amount)){
		return false;
	}

	if (numberOfItems >= maxSize) {
		resize();
	}

	items[numberOfItems] = &item;
	amounts[numberOfItems] = amount;
	numberOfItems++;

	item.setNumberOfAvailableItems(item.getNumberOfAvailableItems() - amount);

	return true;
}

bool ShoppingCart::removeItem(const char* name) {
	int foundInd = find(name);
	if (foundInd == -1) {
		std::cout << ITEM_NOT_FOUND_ERROR << "\n";
		return false;
	}

	// Write over old data
	items[foundInd] = items[numberOfItems - 1];
	amounts[foundInd] = amounts[numberOfItems - 1];

	// Increase the number of avaliable items for the product removed from the cart
	(*items[foundInd]).setNumberOfAvailableItems(amounts[foundInd] + (*items[foundInd]).getNumberOfAvailableItems());

	numberOfItems--;
}

size_t ShoppingCart::itemsCount() const {
	size_t res = 0;
	for (int i = 0; i < numberOfItems; i++) {
		res += amounts[i];
	}
	return res;
}

bool ShoppingCart::exists(const char* itemName) const {
	if (find(itemName) == -1) {
		return false;
	}
	return true;
}

bool ShoppingCart::isEmpty() const {
	return numberOfItems == 0;
}

double ShoppingCart::getPriceOf(const char* itemName) const {
	int foundInd = find(itemName);
	if (foundInd < 0) {
		return 0;
	}
	return (*items[foundInd]).getPrice();
}

double ShoppingCart::totalPrice() const {
	double sum = 0;
	for (int i = 0; i < numberOfItems; i++) {
		sum += (*items[i]).getPrice() * amounts[i];
	}
	return sum;
}

void ShoppingCart::sortByName() {
	for (int i = 0; i < numberOfItems - 1; i++) {

		size_t minInd = getMinNameIndex((const Item**)(items + i), numberOfItems - i) + i;

		if (i != minInd) {
			swapItems((*items[minInd]), (*items[i]));
		}
	}
}

bool ShoppingCart::save(const char* fileName) const{
	std::ofstream ofs(fileName);

	if (!ofs.is_open()) {
		std::cout << FILE_NOT_OPEN_ERR << std::endl;
		return false;
	}

	ofs << "Name,Amount,Price\n";
	for (int i = 0; i < numberOfItems; i++) {
		ofs << (*items[i]).getName() << ',' << amounts[i] << ',' << (*items[i]).getPrice() << '\n';
	}

	ofs.close();
}

void ShoppingCart::print() const {
	for (int i = 0; i < numberOfItems; i++) {
		(*items[i]).print();
		std::cout << " amount: " << amounts[i] << std::endl;
	}
}

ShoppingCart::~ShoppingCart() {
	free();
}

void ShoppingCart::setAmounts(size_t* amounts, size_t numberOfItems) {
	delete[] this->amounts;
	copyAmounts(amounts, numberOfItems);
}

void ShoppingCart::copyAmounts(size_t* amounts, size_t numberOfItems) {
	this->amounts = new size_t[numberOfItems];

	for (int i = 0; i < numberOfItems; i++) {
		this->amounts[i] = amounts[i];
	}
}

void ShoppingCart::copyItems(Item** items, size_t numberOfItems) {
	this->items = new Item* [numberOfItems];

	for (int i = 0; i < numberOfItems; i++) {
		this->items[i] = items[i];
	}
}