#include "Label.h"
#include <iostream>

void Label::setDataDialog()
{
	std::cout << "Input new label: ";
	MyString newLabel;
	std::cin >> newLabel;
	this->textContent = newLabel;
}

Control* Label::clone() const
{
	return new Label(*this);
}
