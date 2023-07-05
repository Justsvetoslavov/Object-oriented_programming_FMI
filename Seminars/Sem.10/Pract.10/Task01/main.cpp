#include <iostream>

#include "Car.h"

int main() {
	FuelTank f1(10);
	Engine e1(123, "Manufacturer1", "Engine 1", 100);
	Tire tires1[4];
	CarBattery cb1(123, "Manufacturer1", "Car battery 1", 20, "HSH7366");
	
	Car c1(f1, e1, tires1, cb1, 10000, 560);

	c1.drive(4);
	std::cout << c1.getMileage() << std::endl; // 10004
	c1.drive(7); // throw 
	std::cout << c1.getMileage() << std::endl; // unchanged, 10004
	std::cout << std::endl;

	c1.fillTank(20);

	FuelTank f2(15);
	Engine e2(116, "Manufacturer2", "Engine 2", 210);
	Tire tires2[4];
	CarBattery cb2(283, "Manufacturer2", "Car battery 2", 25, "AHB7263");

	Car c2(f2, e2, tires2, cb2, 20000, 780);

	c2.drive(14); // 20014
	std::cout << c2.getMileage() << std::endl;
	std::cout << std::endl;

	c2.fillTank(20);

	// Ratios for c1 and c2:
	// c1 - 5,6 
	// c2 - 3,7142...
	Car* winner = dragRace(&c1, &c2);
	std::cout << (winner == &c1 ? "c1" : "c2" )<< std::endl; // c1
	std::cout << std::endl;

	c1.fillTank(10);
	c1.drive(10); 

	winner = dragRace(&c1, &c2); // c1 doesn't have any fuel 
	std::cout << (winner == &c1 ? "c1" : "c2") << std::endl; // c2
	std::cout << std::endl;

	c2.fillTank(20);
	c2.drive(15);

	winner = dragRace(&c1, &c2); // c1 and c2 don't have any fuel 
	std::cout << (winner == nullptr ?  "nullptr" : "") << std::endl; // c2
}
