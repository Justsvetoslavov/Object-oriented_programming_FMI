#include <iostream>
#include "Foodpanda.h"

int main()
{
	Foodpanda fp(4);
	std::cout << "Enter command: \n1 - add restaurant\n2 - add new products in restaurant"
		"\n3 - read order\n4 - exit" << std::endl;
	char command;
	while (true) {
		std::cin >> command;
		if (command == '4')
			break;
		try {
			switch (command) {
			case '1': fp.AddRestaurant();
				break;
			case '2': fp.AddNewProductsInRestaurants();
				break;
			case '3': fp.ReadOrder();
				break;
			default:
				break;
			}
		}
		catch (std::invalid_argument) {
			std::cout << "The argument you gave isn't valid." << std::endl;
		}

		std::cout << "Enter another command: " << std::endl;
	}
}