#pragma once
#include "Control.h"
#include "MyString.h"

class Checkbox : public Control
{
	MyString textContent;
	bool isChecked = false;

public:
	void setDataDialog() override;
	void setTextContent(const MyString& str);
	void setTextContent(MyString&& str);
	Control* clone() const override;
};

