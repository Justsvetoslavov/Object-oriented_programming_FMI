#pragma once
#include "MyString.h"
class Product
{
private:
	MyString name;
public:
	Product() = default;
	Product(const MyString& name);

	const MyString& GetProductName() const;
};