#include "Product.h"
#include <iostream>

Product::Product(const MyString& name) {
	this->name = MyString(name);
}

const MyString& Product::GetProductName() const {
	return this->name;
}