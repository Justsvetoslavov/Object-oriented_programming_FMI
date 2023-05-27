#pragma once
#include "Control.h"
#include "../MyString/MyString.h"

class Label : public Control
{
	MyString _data;

public:
	Label();

	void setDataDialog(const MyString &);
	void setDataDialog(MyString &&) noexcept;
	void setDataDialog(const char *);

	Control *clone() const override;
};
