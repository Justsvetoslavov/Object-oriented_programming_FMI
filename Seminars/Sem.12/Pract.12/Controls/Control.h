#pragma once
#include "stddef.h"

enum class ControlType
{
	Label,
	CheckBox,
	RadioButton,
};

class Control
{
	struct Size
	{
		size_t _width = 0;
		size_t _height = 0;
	};

	Size _size = {0, 0};
	size_t _idxInForm = 0;
	ControlType _type;

public:
	Control(ControlType);
	Control(const Control &) = default;

	void changeSize(size_t, size_t);
	void setIdxInForm(size_t);
	const ControlType &getType() const;

	virtual Control *clone() const = 0;

	virtual ~Control() = default;
};
