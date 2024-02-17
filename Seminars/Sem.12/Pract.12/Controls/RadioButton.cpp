#include "RadioButton.h"

RadioButton::RadioButton()
	: RadioButton(DEFAULT_NUM_OF_OPTIONS)
{
}

RadioButton::RadioButton(size_t numOfOptions)
	: Control(ControlType::RadioButton)
{
	_numOfOptions = numOfOptions;

	if (numOfOptions > 8) // 8 bits in a char (1 byte)
		_options = new char[(numOfOptions + 7) / 8];
	else
		_options = new char[1];
}

void RadioButton::setDataDialog(size_t idx, bool val)
{
	static size_t bucketIdx;

	if (idx < 8)
		bucketIdx = 0;
	else
		bucketIdx = idx / 8;

	static char mask = 1;
	mask <<= 7 - idx % 8;

	if (val)
		_options[bucketIdx] |= mask;
	else
		_options[bucketIdx] &= ~mask;
}

Control *RadioButton::clone() const
{
	return new RadioButton(*this);
}
