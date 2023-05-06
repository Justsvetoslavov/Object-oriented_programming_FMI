#include <iostream>
#include "Engine.h"
#include "Tire.h"
#include "CarBattery.h"
#include "FuelTank.h"
#include "Car.h"

int main()
{
    try
    {
        // prepare car parts
        unsigned int ID = 12345;
        const char *manufacturer = "Bosh";
        const char *description = "This is a car part";
        const char *BatteryID = "BatteryID-54321";
        unsigned short horsePowers = 233;

        Engine engine(ID, manufacturer, description, horsePowers);

        Tire tire(ID, manufacturer, description, 155, 50, 15);
        Tire *tires[4];

        for (unsigned short i = 0; i < 4; ++i)
        {
            tires[i] = &tire;
        }

        CarBattery carBattery(ID, manufacturer, description, 24000, BatteryID);

        // build the car
        Car car1(&engine, tires, &carBattery, 5, 0, 1650);
        Car car2(&engine, tires, &carBattery, 4, 0, 1700);

        car2.drive(3);

        Car *winner = dragRace(&car1, &car2);

        if (!winner)
            std::cout << "No winner\n";
        else
            std::cout << "Winner car: \n"
                      << *winner
                      << "Fuel left: " << winner->getFuelTank().getCurrentLevel() << " liters.\n";
    }
    catch (std::exception &exc)
    {
        std::cout << exc.what() << '\n';
        std::cout << "Task failed. Car not created.";
    }
}
