#include "Competition.h"

Car *Competition::dragRacing(Car *car1, Car *car2) {
    if (car1->getFuelTank().getCurrentFuel() < QUARTER &&
        car2->getFuelTank().getCurrentFuel() < QUARTER)return nullptr;
    if(car1->getFuelTank().getCurrentFuel() < QUARTER)return car2;
    if(car2->getFuelTank().getCurrentFuel() < QUARTER)return car1;

    return car1->getWeight() / car1->getEngine().getHp() < car2->getWeight() / car2->getEngine().getHp()?car1:car2;
}
