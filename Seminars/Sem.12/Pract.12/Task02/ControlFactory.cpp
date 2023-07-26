#include "ControlFactory.h"

#include "Checkbox.h"
#include "Label.h"
#include "RadioButton.h"

Control* ControlFactory::genControl(const ControlType controlType)
{
	switch (controlType)
	{
	case ControlType::label:
		return new Label();
	case ControlType::checkBox:
		return new Checkbox();
	case ControlType::radioButton:
		return new RadioButton();
	}
}
