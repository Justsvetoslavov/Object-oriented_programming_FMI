#include "Car/Car.h"

int main() {
    Tires tr(1, "rds", "sds", 155, 31, 13);
    Tires arr[4] {tr, tr, tr, tr};
    Battery battery(2,"battery", "common battery", 5000, "hjh34");
    Reservoir res(4, "reser", "common reser", 0.3);
    Reservoir res2(4, "reser", "common reser", 0.4);
    Engine eng(6, "engine", "common engine", 150);
    Car car1(res, eng, arr, battery, 10000, 5000);
    Car car2(res2, eng, arr, battery, 10000, 6000);
    Car *car3 = dragRace(&car1, &car2);
    std::cout << car3->getHorsePower();
}