#include <iostream>
#include "Computer.h"
#include "Pc.h"
#include "Laptop.h"
#include "GamingConsole.h"

int main()
{
    Computer* comp = new Pc();

    comp->printType();
}