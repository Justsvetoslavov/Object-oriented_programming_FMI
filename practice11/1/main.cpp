#include "Vehicle/Autobus/Autobus.h"
#include "Vehicle/Bike/Bike.h"
#include "Vehicle/Car/Car.h"
#include "Vehicle/Tir/Tir.h"

const int WHEELS = 2;

int main() {
    Tires tire(2, "tire", "common tire", 155, 30, 13);
    Tires tire2(6, "tire2", "common tire2", 156, 31, 14);
    Tires tires[WHEELS];
    for (int i = 0; i < WHEELS; ++i)
        tires[i] = tire;
    Bike bike(tires, WHEELS, EngineType::none, 6, 80);
    bike.GetPermit();
    bike.changeTire(tire2, 0);
}