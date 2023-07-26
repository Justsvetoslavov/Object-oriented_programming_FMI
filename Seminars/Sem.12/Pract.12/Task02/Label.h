#pragma once
#include "Control.h"
#include "MyString.h"

class Label: public Control
{
	MyString textContent;

	void setDataDialog() override;
	Control* clone() const override;
};

