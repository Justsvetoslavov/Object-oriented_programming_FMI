#include <iostream>
#include "Car.h"
int main() {

    Tyre tyres[4];
    Engine eng(1,"Mercedes","CL 65 AMG",612);
    Battery btr(1,"Bosch","kraden",500,123);
    FuelTank ft(1,"Jelezen","i tva e kradeno",100);
    ft.fill(60);
    Car car1(std::move(eng),std::move(ft),tyres,std::move(btr));

    Tyre tyres1[4];
    Engine eng1(1,"Audi","Koshnica",78);
    Battery btr1(1,"Iliqnci","kraden",500,123);
    FuelTank ft1(1,"Jelezen","i tva e kradeno",100);
    ft1.fill(70);

    Car car2(std::move(eng1),std::move(ft1),tyres,std::move(btr1));

    Car winner = dragRace(car1,car2);

    std::cout<<winner.getHP();
    return 0;
}
