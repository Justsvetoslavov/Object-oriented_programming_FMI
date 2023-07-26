#pragma once
#include "Control.h"

class ControlFactory
{
public:
	static Control* genControl(ControlType controlType);
};

