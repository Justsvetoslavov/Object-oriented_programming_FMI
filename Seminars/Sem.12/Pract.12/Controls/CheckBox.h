#pragma once
#include "Control.h"
#include "../MyString/MyString.h"

class CheckBox : public Control
{
	MyString _data;
	bool _state = false;

public:
	CheckBox();

	void setDataDialog(const MyString &, bool state);
	void setDataDialog(MyString &&, bool state);
	void setDataDialog(const char *, bool state);

	Control *clone() const override;
};
