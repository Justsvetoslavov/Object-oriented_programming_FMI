#include "ControlFactory.h"
#include "../Controls/Label.h"
#include "../Controls/CheckBox.h"
#include "../Controls/RadioButton.h"

Control *controlFactory(ControlType type)
{
    switch (type)
    {
    case ControlType::Label:
        return new Label();
    case ControlType::CheckBox:
        return new CheckBox();
    case ControlType::RadioButton:
        return new RadioButton();
    }
    return nullptr;
}

Control *copyControlFactory(const Control &control)
{
    switch (control.getType())
    {
    case ControlType::Label:
        return new Label((const Label &)(control));
    case ControlType::CheckBox:
        return new CheckBox((const CheckBox &)(control));
    case ControlType::RadioButton:
        return new RadioButton((const RadioButton &)(control));
    }
    return nullptr;
}

Control *moveControlFactory(Control &&control)
{
    switch (control.getType())
    {
    case ControlType::Label:
        return new Label(std::move((const Label &)(control)));
    case ControlType::CheckBox:
        return new CheckBox(std::move((const CheckBox &)(control)));
    case ControlType::RadioButton:
        return new RadioButton(std::move((const RadioButton &)(control)));
    }
    return nullptr;
}