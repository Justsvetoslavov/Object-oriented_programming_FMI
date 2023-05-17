#include "GamingConsole.h"

GamingConsole::GamingConsole(double CPU_power, const MyString& videoCardModel, int powerSupply, int RAM,
	const MyString& joystick, const MyString& monitor)
	: Computer(CPU_power, videoCardModel, powerSupply, RAM) {
	_joystick = joystick;
	_monitor = monitor;
}

void GamingConsole::printComputerType() const{
	std::cout << "Computer type: GamingConsole" << std::endl;
}

const MyString& GamingConsole::getPeripheralDevices() const {
	return _joystick + " " + _monitor;
}