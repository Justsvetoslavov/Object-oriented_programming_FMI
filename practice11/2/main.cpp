#include "Computer/GamingConsole/GamingConsole.h"
#include "Computer/Laptop/Laptop.h"
#include "Computer/PC/PC.h"

int main() {
    Computer **comp = new Computer*[3];
    comp[0] = new Laptop(3.6, "j33", 50, 16,"Mouse", "keyboard", "monitor");
    comp[1] = new PC(4.0, "asd", 100, 32, "razor", "Keyboard", "micro", "headphone");
    comp[2] = new GamingConsole(2.5, "ps2", 70, 4, "gamepad", "none");
    for (int i = 0; i < 3; ++i) {
        comp[i]->GetType();
        comp[i]->GetDevices();
    }
    for (int i = 0; i < 3; ++i)
        delete comp[i];
    delete[] comp;
}