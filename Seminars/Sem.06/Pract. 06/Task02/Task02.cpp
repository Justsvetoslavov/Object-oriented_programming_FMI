#include <iostream>
#include "ShoppingCart.h"
const int BUFFER_SIZE = 256;
void AddItem(ShoppingCart& sc) {
	std::cout << "Enter item name: ";
	char name[BUFFER_SIZE];
	std::cin >> name;
	std::cout << "Enter item availability: ";
	bool isAvailable;
	std::cin >> isAvailable;
	std::cout << "Enter item price: ";
	double price;
	std::cin >> price;
	if (!sc.AddItem(Item(name, isAvailable, price)))
		std::cout << "This item already exists in the shopping cart!" << std::endl;
	else
		std::cout << "Item added successfully!" << std::endl;

}

void RemoveItem(ShoppingCart& sc) {
	std::cout << "Enter item name to be removed: ";
	char name[BUFFER_SIZE];
	std::cin >> name;
	if (!sc.RemoveItem(name))
		std::cout << "Item with this name doesn't exist!" << std::endl;
	else
		std::cout << "Item removed successfully!" << std::endl;
}

void ItemExists(ShoppingCart& sc) {
	std::cout << "Enter item name to be removed: ";
	char name[BUFFER_SIZE];
	std::cin >> name;
	std::cout << sc.Exists(name);
}

void GetPrice(ShoppingCart& sc) {
	std::cout << "Enter item name: ";
	char name[BUFFER_SIZE];
	std::cin >> name;
	std::cout << sc.GetPriceOf(name);
}

int main()
{
	ShoppingCart sc;
	std::cout << "Enter command:\n1 - add item\n2 - remove item\n3 - get items count"
		"\n4 - does item exist\n5 - is shopping cart empty\n6 - get price of item"
		"\n7 - get total price of shopping cart\n8 - sort shopping cart by name"
		"\n9 - save shopping cart\n0 - exit" << std::endl;
	char command;
	while (true) {
		std::cin >> command;
		if (command == '0')
			break;

		switch (command) {
		case '1': AddItem(sc);
			break;
		case '2': RemoveItem(sc);
			break;
		case '3': std::cout <<  sc.ItemsCount() << std::endl;
			break;
		case '4': ItemExists(sc);
			break;
		case '5': std::cout << sc.IsEmpty() << std::endl;
			break;
		case '6': GetPrice(sc);
			break;
		case '7': std::cout << sc.TotalPrice();
			break;
		case '8': sc.SortByName();
			break;
		case '9': sc.Save("file.csv");
			break;
		}
		std::cout << "Enter another command: ";
	}
}