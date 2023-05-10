#include "Car/Car.h"

int main() {
    Tires tr(1, "rds", "sds", 155, 31, 13);
    Tires tires[4];
    for (int i = 0; i < 4; ++i)
        tires[i] = tr;
    Battery batt(4, "akk", "test", 25, "232");
    Engine eng(5, "Mot", "Engine", 100);
    Reservoir reservoir(6, "Res", "reser", 0.6);
    Car car(reservoir, eng, tires, batt, 100, 5);
    std::cout << dragRace(&car, &car);
}