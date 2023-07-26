#include "Checkbox.h"

void Checkbox::setDataDialog()
{
	this->isChecked = !this->isChecked;
}

void Checkbox::setTextContent(const MyString& str)
{
	this->textContent = str;
}

void Checkbox::setTextContent(MyString&& str)
{
	this->textContent = std::move(str);
}

Control* Checkbox::clone() const
{
	return new Checkbox(*this);
}
