#include <iostream>
#include "LAPTOP.h"
#include "PC.h"

int main()
{
    try
    {
        PC pc(1256.23, "serial_num_BUIF438", 120, 5);
        pc.computerType();

        Laptop laptop(1256.23, "serial_num_BUIF438", 120, 5);
        laptop.computerType();
        laptop.availablePeripherals();
    }
    catch (std::exception &exc)
    {
        std::cout << exc.what();
    }
};