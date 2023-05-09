#include "Order.h"

void Order::CopyFrom(const Order& other) {
	this->products = new Product[other.productsCount];
	this->productsCount = other.productsCount;
	this->products = other.products;
	this->restaurantName = other.restaurantName;
}
void Order::MoveFrom(Order&& other) {
	this->products = other.products;
	this->restaurantName = std::move(other.restaurantName);
	other.products = nullptr;
	other.productsCount = 0;
	other.productsCapacity = 0;

}
void Order::Free() {
	delete[] this->products;
	this->products = nullptr;
	this->productsCapacity = 0;
	this->productsCount = 0;
}

Order::Order(const MyString& restaurantName, size_t productCapacity) {
	this->restaurantName = MyString(restaurantName);
	this->products = new Product[productCapacity];
	this->productsCapacity = productCapacity;
}
Order::Order(const Order& other) {
	CopyFrom(other);
}
Order& Order::operator=(const Order& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}

Order::Order(Order&& other) noexcept {
	MoveFrom(std::move(other));
}
Order& Order::operator=(Order&& other) noexcept {
	if (this != &other) {
		Free();
		MoveFrom(std::move(other));
	}
	return *this;

}
Order::~Order() {
	Free();
}
void Order::Resize(size_t newCapacity) {
	Product* temp = new Product[newCapacity];
	delete[] this->products;
	for (size_t i = 0; i < newCapacity; i++)
	{
		this->products[i] = temp[i];
	}
	this->productsCapacity = newCapacity;
	delete[] temp;
}

void Order::AddProduct(const char* order) {
	if (this->productsCount >= this->productsCapacity)
		Resize(this->productsCapacity * 2);

	this->products[productsCount++] = Product(order);
}

void Order::ReceiveOrder(const Order& order) {
	if (strcmp(this->restaurantName.c_str(), order.GetRestaurantName()))
		throw std::invalid_argument("This order is not for this restaurant!");

	bool foundItem = false;
	for (size_t i = 0; i < order.GetProductsCount(); i++)
	{
		for (size_t j = 0; j < this->productsCount; j++)
		{
			if (!strcmp(order.GetProducts()[i].GetProductName().c_str(),
				this->products[j].GetProductName().c_str()))
				foundItem = true;
		}
		if (!foundItem)
			throw std::invalid_argument("This restaurant do not have one of these products!");
	}
	std::cout << "Order received!" << std::endl;
}

const char* Order::GetRestaurantName() const {
	return this->restaurantName.c_str();
}

const Product* Order::GetProducts() const {
	return this->products;
}

size_t Order::GetProductsCount() const {
	return this->productsCount;
}