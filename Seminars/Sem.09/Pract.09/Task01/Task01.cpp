#include <iostream>
#include "Foodpanda.h"

void AddRestaurant(Foodpanda& fp) {
	std::cout << "Enter restaurant name: ";
	MyString restName;
	std::cin >> restName;
	size_t restCapacity;
	std::cout << "Enter restaurant capacity: ";
	std::cin >> restCapacity;
	fp.AddRestaurant(restName, restCapacity);
}

void ReadOrder(Foodpanda& fp) {
	std::cout << "Enter restaurant name: ";
	MyString restaurantName;
	std::cin >> restaurantName;
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
	fp.ReadOrder(restaurantName, newOrder);
}


void AddNewProductsInRestaurant(Foodpanda& fp) {
	std::cout << "Enter restaurant name: ";
	MyString restaurantName;
	std::cin >> restaurantName;
	std::cout << "Enter products count: " << std::endl;
	size_t productsCount;
	std::cin >> productsCount;
	MyString* products = new MyString[productsCount];
	for (size_t i = 0; i < productsCount; i++)
	{
		std::cout << "Enter product to be added in restaurant: " << std::endl;
		MyString productName;
		std::cin >> productName;
		products[i] = productName;
	}
	fp.AddNewProductsInRestaurant(restaurantName, products, productsCount);
	delete[] products;
}
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
			case '1': AddRestaurant(fp);
				break;
			case '2': AddNewProductsInRestaurant(fp);
				break;
			case '3': ReadOrder(fp);
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


