#pragma once
#include "Control.h"
#include "MyString.h"
#include "DynamicArray.hpp"

class RadioButton:public Control
{
	DynamicArray<MyString> options;
	size_t maxOptions = 0;

	unsigned activeOption = 0;

public:
	RadioButton();
	RadioButton(size_t maxOptions);

	void addOption(const MyString& textContent);
	void addOption(MyString&& textContent);

	Control* clone() const override;

	void setDataDialog() override;
};

