#include "CheckBox.h"

CheckBox::CheckBox()
	: Control(ControlType::CheckBox)
{
}

void CheckBox::setDataDialog(const MyString &data, bool state)
{
	_data = data;
	_state = state;
}

void CheckBox::setDataDialog(MyString &&data, bool state)
{
	_data = std::move(data);
	_state = state;
}

void CheckBox::setDataDialog(const char *data, bool state)
{
	if (!data)
		throw std::invalid_argument("Empty data passed (nullptr).");

	_data = MyString(data);
	_state = state;
}

Control *CheckBox::clone() const
{
	return new CheckBox(*this);
}
