#include "Laptop.h"

Laptop::Laptop(double CPU_power, const MyString& videoCardModel, int powerSupply, int RAM,
	const MyString& mousePad, const MyString& keyboard, const MyString& monitor)
	: Computer(CPU_power, videoCardModel, powerSupply, RAM) {
	_mousePad = mousePad;
	_keyboard = keyboard;
	_monitor = monitor;
}

void Laptop::printComputerType() const{
	std::cout << "Computer type: Laptop" << std::endl;
}

const MyString& Laptop::getPeripheralDevices() const{
	return _mousePad + " " + _keyboard + " " + _monitor;
}