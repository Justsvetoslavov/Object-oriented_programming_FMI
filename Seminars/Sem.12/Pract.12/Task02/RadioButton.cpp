#include "RadioButton.h"

#include <iostream>

RadioButton::RadioButton():RadioButton(2)
{
}

RadioButton::RadioButton(const size_t maxOptions)
{
	this->maxOptions = maxOptions;
	options = DynamicArray<MyString>(maxOptions);
}

void RadioButton::addOption(const MyString& textContent)
{
	this->options.pushBack(textContent);
}

void RadioButton::addOption(MyString&& textContent)
{
	this->options.pushBack(std::move(textContent));
}

Control* RadioButton::clone() const
{
	return new RadioButton(*this);
}

void RadioButton::setDataDialog()
{
	unsigned newOptionIndex = 0;
	std::cout << "Input new option index: ";
	std::cin >> newOptionIndex;

	if (newOptionIndex >= this->options.getSize())
	{
		throw std::range_error("Index out of range.");
	}
	this->activeOption = newOptionIndex;
}
