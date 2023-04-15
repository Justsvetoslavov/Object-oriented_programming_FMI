#include <iostream>
#include "ShoppingCart.h"

const int name_Max_Size = 50;

void PrintMenu() {
	std::cout << "-------Menu-------\n";
	std::cout << "1 - add item to the cart\n";
	std::cout << "2 - remove item from the cart\n";
	std::cout << "3 - shows the count of items in the cart\n";
	std::cout << "4 - checks if an item is in the cart\n";
	std::cout << "5 - gives information whether the cart is empty\n";
	std::cout << "6 - shows an item's price\n";
	std::cout << "7 - shows the total price of the items in the cart\n";
	std::cout << "8 - sorts the items in the cart by name\n";
	std::cout << "9 - saves the items to a file\n";
	std::cout << "10 - quit\n";
}

void InputName(char* name) {
	std::cout << "Enter item name: ";
	std::cin.getline(name, name_Max_Size);
}

Item NewItem() {
	char name[name_Max_Size];
	InputName(name);
	std::cout << "Enter price: ";
	double price = 0;
	std::cin >> price;
	return Item(name, 1, price);
}

void AddNewItem(ShoppingCart& cart) {
	Item item = NewItem();
	if (cart.AddItem(item))
		std::cout << "Item successfully added!\n";
	else
		std::cout << "There is already an item with that name!\n";
}

void RemoveItemFromCart(ShoppingCart& cart) {
	char name[name_Max_Size];
	InputName(name);
	if (cart.RemoveItem(name))
		std::cout << "Item successfully removed\n";
	else
		std::cout << "There is no item with that name\n";
}

void DoesExist(const ShoppingCart& cart) {
	char name[name_Max_Size];
	InputName(name);
	if (cart.Exists(name))
		std::cout << "The item is in the cart\n";
	else
		std::cout << "The item is not in the cart\n";
}

void SaveToFile(const ShoppingCart& cart) {
	std::cout << "Enter file name: ";
	char name[name_Max_Size];
	std::cin.getline(name, name_Max_Size);
	if (cart.Save(name))
		std::cout << "Shopping cart saved successfully to the file\n";
	else
		std::cout << "Error saving the shopping cart to the file\n";
}

void MenuOptions() {
	ShoppingCart cart;
	bool hasQuit = false;
	int command;

	while (!hasQuit) {
		std::cin >> command;
		std::cin.ignore();

		switch (command) {
		case 1: {
			AddNewItem(cart);
			break;
		}
		case 2: {
			RemoveItemFromCart(cart);
			break;
		}
		case 3: {
			std::cout << "The count of the items in the cart is: " << cart.ItemsCount();
			break;
		}
		case 4: {
			DoesExist(cart);
			break;
		}
		case 5: {
			if (cart.IsEmpty())
				std::cout << "The cart is empty\n";
			else
				std::cout << "The cart is not empty\n";
			break;
		}
		case 6: {
			char name[name_Max_Size];
			InputName(name);
			std::cout << "Price: " << cart.GetPriceOf(name) << std::endl;
			break;
		}
		case 7: {
			std::cout << "Total price of items in the cart is: " << cart.TotalPrice() << std::endl;
			break;
		}
		case 8: {
			cart.SortByName();
			std::cout << "Items are sorted\n";
			break;
		}
		case 9: {
			SaveToFile(cart);
			break;
		}
		case 10: {
			std::cout << "Goodbye!\n";
			hasQuit = true;
			break;
		}
		default:
		{
			std::cout << "Wrong command!\n";
			break;
		}
		}
	}
}

int main()
{
	PrintMenu();
	MenuOptions();
}
