#include <iostream>
#include "Tire.h"
#include "Car.h"
#include "Point.h"

int main()
{
    try
    {
        const Tire tires[4]{
            Tire(1, "Bosch", "info", 155, 50, 15),
            Tire(1, "Bosch", "info", 155, 50, 15),
            Tire(1, "Bosch", "info", 155, 50, 15),
            Tire(1, "Bosch", "info", 155, 50, 15)};

        Car car(tires, 53.6, EngineType::electric, 4, 4);

        Point A(5, 8);
        Point B(48, 95);

        std::cout << "Travel time: " << car.travelTime(A, B) << '\n';
        car.allowedRouteOn();
        std::cout << '\n';
        car.changeEngineType(EngineType::diesel);
        car.changeTire(Tire(2, "cool", "new info", 160, 65, 17), 3);
    }
    catch (std::exception &exc)
    {
        std::cout << exc.what();
    }
}