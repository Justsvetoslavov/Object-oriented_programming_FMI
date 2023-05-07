#include <iostream>
#include <fstream>
#include "Car/Car.cpp"
#include "Competition/Competition.cpp"
int main() {


    Tier tier (252,32,21,1,"ToyoTiers","No description");
    TirePack tierPack(4);
    tierPack.setTiersTo(tier);

    Engine engine2(80,2,"Lada","1.6");
    Engine engine1(140,2,"Mercedes","2.0");

    Battery battery2("A9342",1800,3,"Skoda","No description");
    FuelTank fuelTank(0.3);
    FuelTank fuelTank1(0.3);

    Car *car = new Car(std::move(engine2),std::move(battery2),
            std::move(fuelTank),std::move(tierPack),
            1800,200000);

    Car *car2 = new Car(std::move(engine1),std::move(battery2),
            std::move(fuelTank1),std::move(tierPack),
            1900,200000);


    Competition competition;

    Car *Winner = competition.dragRacing(car,car2);

}