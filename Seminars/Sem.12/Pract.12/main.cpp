#include <iostream>
#include "Form.h"
#include "Controls/Label.h"

int main()
{
    Form form(50, 50, "new form");
    Label label;

    label.setDataDialog("new label");

    form.appendControl(label);
    form.getControl(0).changeSize(5, 6);
}