#include "Label.h"

Label::Label()
	: Control(ControlType::Label)
{
}

void Label::setDataDialog(const MyString &data)
{
	_data = data;
}

void Label::setDataDialog(MyString &&data) noexcept
{
	_data = std::move(data);
}

void Label::setDataDialog(const char *data)
{
	if (!data)
		throw std::invalid_argument("Empty data passed (nullptr).");

	_data = std::move(MyString(data));
}

Control *Label::clone() const
{
	return new Label(*this);
}
