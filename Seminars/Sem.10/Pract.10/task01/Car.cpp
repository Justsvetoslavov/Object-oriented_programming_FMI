#include "Car.h"
#define q4 0.4
Car::Car(unsigned int ftID, const MyString &ftName, const MyString &ftDescription , double ftCapacity,
         unsigned int engineID, const MyString &engineName, const MyString &engineDescription, unsigned int engineHp,
         unsigned int batteryID, const MyString &batteryName, const MyString &batteryDescription,
         unsigned int batterCapcity, unsigned int batteryID1, double kiometers, double weigth):
        engine(engineID,engineName,engineDescription,engineHp),
        fuelTank(ftID,ftName,ftDescription,ftCapacity),
        battery(batteryID,batteryName,batteryDescription,batterCapcity,batteryID1){

}

    Car::Car(Engine &&eng, FuelTank &&ft, Tyre *tyresArr, Battery &&btr): engine(eng), fuelTank(ft), battery(btr) {
    tyres=tyresArr;
    tyresArr= nullptr;
}

const FuelTank &Car::getFuelTank() const {
    return fuelTank;
}

unsigned int Car::getHP() const {
    return engine.getHp();
}

double Car::getWeight() const {
    return weight;
}

Car &Car::drive(double km) {
    if(km<0){
        return *this;
    }
    kilometers+=km;
    fuelTank.use(km);
}

Car dragRace(  Car& car1,  Car&car2){
    car1.drive(q4);
    car2.drive(q4);

    if(car1.getFuelTank().getLiters()==0 &&car2.getFuelTank().getLiters()==0){
        return (car1.getHP()/car1.getWeight()>car2.getHP()/car2.getWeight())
        ?car1:car2;
    } else if(car1.getFuelTank().getLiters()==0){
        return car2;
    }else if(car2.getFuelTank().getLiters()==0){
        return car1;
    }
    return (car1.getHP()/car1.getWeight()>car2.getHP()/car2.getWeight())
        ?car2:car1;
}