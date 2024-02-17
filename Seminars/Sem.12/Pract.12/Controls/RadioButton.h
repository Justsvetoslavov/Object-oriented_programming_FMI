#pragma once
#include "Control.h"

static const unsigned DEFAULT_NUM_OF_OPTIONS = 8;

class RadioButton : public Control
{
	char *_options = nullptr;
	size_t _numOfOptions = 0;

public:
	RadioButton();
	RadioButton(size_t);

	void setDataDialog(size_t, bool);

	Control *clone() const override;
};
