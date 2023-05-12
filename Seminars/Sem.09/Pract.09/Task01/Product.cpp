#include "Product.h"

Product::Product(const char* name){
	this->name = MyString(name);
}

const char* Product::GetProduct() const{
	return name.c_str();
}
