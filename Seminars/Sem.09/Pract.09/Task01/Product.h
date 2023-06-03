#pragma once
#include "MyString.h"
class Product{
private:
	MyString name;

public:
	Product() = default;
	Product(const char*);

	const char* GetProduct() const;
};

