#include "../Controls/Control.h"

Control *controlFactory(ControlType type);
Control *copyControlFactory(const Control &control);
Control *moveControlFactory(Control &&control);
