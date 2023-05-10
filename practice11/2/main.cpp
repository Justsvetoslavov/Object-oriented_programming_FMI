#include "Computer/GamingConsole/GamingConsole.h"
#include "Computer/Laptop/Laptop.h"
#include "Computer/PC/PC.h"

int main() {
    Computer **comp = new Computer*[3];
    comp[0] = new Laptop("Mouse", "keyboard", "monitor");

}